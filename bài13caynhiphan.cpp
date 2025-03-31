#include <iostream>
#include <fstream>

using namespace std;

struct nut {
    float giatri;
    nut *trai;
    nut *phai;
};

typedef nut *CAY;

// Ham tao mot nut moi
nut *taoNut(float giatri) {
    nut *p = new nut;
    p->giatri = giatri;
    p->trai = nullptr;
    p->phai = nullptr;
    return p;
}

// Ham chen gia tri vao cay
void chen(CAY &goc, float giatri) {
    if (goc == nullptr) {
        goc = taoNut(giatri);
        return;
    }
    if (giatri < goc->giatri) {
        chen(goc->trai, giatri);
    } else {
        chen(goc->phai, giatri);
    }
}

// Ham ghi cay vao file theo NLR
void NLR(CAY goc, FILE *tep) {
    if (goc == nullptr) return;
    fwrite(&goc->giatri, sizeof(float), 1, tep);
    NLR(goc->trai, tep);
    NLR(goc->phai, tep);
}

// Ham xuat cay ra file
int xuat(const char *tenfile, CAY goc) {
    FILE *tep = fopen(tenfile, "wb");
    if (tep == nullptr) return 0;
    NLR(goc, tep);
    fclose(tep);
    return 1;
}

// Ham doc cay tu file
void nhap(CAY &goc, const char *tenfile) {
    FILE *tep = fopen(tenfile, "rb");
    if (tep == nullptr) return;
    float giatri;
    while (fread(&giatri, sizeof(float), 1, tep)) {
        chen(goc, giatri);
    }
    fclose(tep);
}

// Ham duyet cay theo LNR de kiem tra
void LNR(CAY goc) {
    if (goc == nullptr) return;
    LNR(goc->trai);
    cout << goc->giatri << " ";
    LNR(goc->phai);
}

int main() {
    CAY goc = nullptr;
    float danhsach[] = {10.5, 5.2, 15.8, 3.1, 9.6, 12.7, 18.4, 7.3, 20.9};
    int n = sizeof(danhsach) / sizeof(danhsach[0]);

    for (int i = 0; i < n; i++) {
        chen(goc, danhsach[i]);
    }

    cout << "Cay ban dau (LNR): ";
    LNR(goc);
    cout << endl;

    xuat("data.out", goc);

    CAY gocMoi = nullptr;
    nhap(gocMoi, "data.out");

    cout << "Cay doc tu file (LNR): ";
    LNR(gocMoi);
    cout << endl;

    return 0;
}

