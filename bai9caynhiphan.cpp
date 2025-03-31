#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cay nhi phan
struct nut {
    float gia_tri;
    struct nut* conTrai;
    struct nut* conPhai;
};

typedef struct nut NUT;
typedef NUT* CAY;

// Ham tao mot nut moi
NUT* taoNut(float x) {
    NUT* nutMoi = (NUT*)malloc(sizeof(NUT));
    if (nutMoi == NULL) {
        printf("Loi cap phat bo nho!\n");
        return NULL;
    }
    nutMoi->gia_tri = x;
    nutMoi->conTrai = NULL;
    nutMoi->conPhai = NULL;
    return nutMoi;
}

// Ham chen mot gia tri vao cay
void chen(CAY* goc, float x) {
    if (*goc == NULL) {
        *goc = taoNut(x);
        return;
    }
    if (x < (*goc)->gia_tri) {
        chen(&((*goc)->conTrai), x);
    } else {
        chen(&((*goc)->conPhai), x);
    }
}

// Ham duyet cay theo NLR va ghi vao file
void NLR(CAY goc, FILE* tep) {
    if (goc == NULL)
        return;
    fwrite(&(goc->gia_tri), sizeof(float), 1, tep);
    NLR(goc->conTrai, tep);
    NLR(goc->conPhai, tep);
}

// Ham xuat cay ra file nhi phan
int xuat(char *tenTep, CAY goc) {
    FILE* tep = fopen(tenTep, "wb");
    if (tep == NULL)
        return 0;
    NLR(goc, tep);
    fclose(tep);
    return 1;
}

// Ham doc va in ra noi dung file de kiem tra
void docTep(char *tenTep) {
    FILE* tep = fopen(tenTep, "rb");
    if (tep == NULL) {
        printf("Khong mo duoc tep!\n");
        return;
    }
    float x;
    printf("Noi dung tep: ");
    while (fread(&x, sizeof(float), 1, tep)) {
        printf("%.2f ", x);
    }
    printf("\n");
    fclose(tep);
}

// Ham chinh de chay chuong trinh
int main() {
    CAY goc = NULL;
    // Them mot so gia tri vao cay
    chen(&goc, 5.5);
    chen(&goc, 2.2);
    chen(&goc, 8.8);
    chen(&goc, 1.1);
    chen(&goc, 3.3);
    
    // Ghi cay vao file
    if (xuat("data.out", goc)) {
        printf("Da ghi xong!\n");
    } else {
        printf("Loi khi ghi tep!\n");
    }

    // Doc lai file de kiem tra
    docTep("data.out");

    return 0;
}

