#include <iostream>

using namespace std;

struct nut {
    int giatri;
    nut *trai;
    nut *phai;
};

typedef nut *CAY;

// Ham tao mot nut moi
nut *taoNut(int giatri) {
    nut *p = new nut;
    p->giatri = giatri;
    p->trai = nullptr;
    p->phai = nullptr;
    return p;
}

// Ham chen mot gia tri vao cay nhi phan tim kiem
void chen(CAY &goc, int giatri) {
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

// Ham duyet cay theo RNL (giam dan)
void RNL(CAY goc) {
    if (goc == nullptr) return;
    RNL(goc->phai);
    cout << goc->giatri << " ";
    RNL(goc->trai);
}

int main() {
    CAY goc = nullptr;
    int danhsach[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = sizeof(danhsach) / sizeof(danhsach[0]);

    for (int i = 0; i < n; i++) {
        chen(goc, danhsach[i]);
    }

    cout << "Cay duyet theo RNL (giam dan): ";
    RNL(goc);
    cout << endl;

    return 0;
}

