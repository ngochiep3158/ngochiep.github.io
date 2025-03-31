#include <iostream>
#include <fstream>
using namespace std;

struct nut {
    float gia_tri;
    nut* trai;
    nut* phai;
};
typedef nut* CAY;

void LNR(CAY goc, ofstream &tep) {
    if (goc == NULL)
        return;
    LNR(goc->trai, tep);
    tep.write(reinterpret_cast<const char*>(&goc->gia_tri), sizeof(float));
    LNR(goc->phai, tep);
}

int Xuat(const char *ten_tep, CAY goc) {
    ofstream tep(ten_tep, ios::binary);
    if (!tep.is_open())
        return 0;
    LNR(goc, tep);
    tep.close();
    return 1;
}

CAY taoNut(float gia_tri) {
    CAY nut_moi = new nut;
    nut_moi->gia_tri = gia_tri;
    nut_moi->trai = NULL;
    nut_moi->phai = NULL;
    return nut_moi;
}

void chenNut(CAY &goc, float gia_tri) {
    if (goc == NULL) {
        goc = taoNut(gia_tri);
        return;
    }
    if (gia_tri < goc->gia_tri)
        chenNut(goc->trai, gia_tri);
    else
        chenNut(goc->phai, gia_tri);
}

int main() {
    CAY goc = NULL;
    chenNut(goc, 5.5);
    chenNut(goc, 2.3);
    chenNut(goc, 8.1);
    chenNut(goc, 1.2);
    chenNut(goc, 3.7);

    if (Xuat("data.out", goc))
        cout << "Da ghi cay vao tap tin thanh cong.\n";
    else
        cout << "Loi khi mo tap tin.\n";

    return 0;
}

