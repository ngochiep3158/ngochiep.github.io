#include <iostream>

using namespace std;

struct nut {
    int gt;
    nut *trai;
    nut *phai;
};

typedef nut *CAY;

// H�m t?o m?t n�t m?i
nut *taoNut(int gt) {
    nut *p = new nut;
    p->gt = gt;
    p->trai = nullptr;
    p->phai = nullptr;
    return p;
}

// H�m ch�n m?t gi� tr? v�o c�y nh? ph�n t?m ki?m
void chen(CAY &goc, int gt) {
    if (goc == nullptr) {
        goc = taoNut(gt);
        return;
    }
    if (gt < goc->gt) {
        chen(goc->trai, gt);
    } else {
        chen(goc->phai, gt);
    }
}

// H�m duy?t c�y theo LNR (Inorder Traversal)
void LNR(CAY goc) {
    if (goc == nullptr) return;
    LNR(goc->trai);
    cout << goc->gt << " ";
    LNR(goc->phai);
}

int main() {
    CAY goc = nullptr;
    int ds[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = sizeof(ds) / sizeof(ds[0]);

    for (int i = 0; i < n; i++) {
        chen(goc, ds[i]);
    }

    cout << "Cay duyet theo LNR: ";
    LNR(goc);
    cout << endl;

    return 0;
}

