#include <iostream>
using namespace std;

// Cau truc cay nhi phan
struct node
{
    int info;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE *TREE;

// Ham khoi tao cay nhi phan
void Init(TREE &t)
{
    t = NULL;
}

// Ham tao node moi
NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Ham tao cay tu mang
void CreateTree(TREE &t, int a[], int &i, int n)
{
    if (i < n)
    {
        if (a[i] == 0)
            t = NULL; // Neu gia tri la 0, khong tao node
        else
        {
            t = CreateNode(a[i]); // Tao node
            i++;
            CreateTree(t->pLeft, a, i, n); // Tao cay con trai
            i++;
            CreateTree(t->pRight, a, i, n); // Tao cay con phai
        }
    }
}

// Ham dem so luong cac nut trong cay
int DemNode(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = DemNode(Root->pLeft);
    int b = DemNode(Root->pRight);
    return (a + b + 1);
}

// Ham tinh tong cac nut trong cay
int TongNode(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = TongNode(Root->pLeft);
    int b = TongNode(Root->pRight);
    return (a + b + Root->info);
}

// Ham tinh trung binh cong cac nut trong cay
float TrungBinhCong(TREE Root)
{
    int s = TongNode(Root);
    int dem = DemNode(Root);
    if (dem == 0)
        return 0;
    return (float)s / dem;
}

// Ham dem so luong cac nut duong
int DemDuong(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = DemDuong(Root->pLeft);
    int b = DemDuong(Root->pRight);
    if (Root->info > 0)
        return (a + b + 1);
    return (a + b);
}

// Ham tinh tong cac nut duong
int TongDuong(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = TongDuong(Root->pLeft);
    int b = TongDuong(Root->pRight);
    if (Root->info > 0)
        return (a + b + Root->info);
    return (a + b);
}

// Ham tinh trung binh cong cac so duong trong cay
float TrungBinhDuong(TREE Root)
{
    int s = TongDuong(Root);
    int dem = DemDuong(Root);
    if (dem == 0)
        return 0;
    return (float)s / dem;
}

// Ham dem so luong cac nut am
int DemAm(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = DemAm(Root->pLeft);
    int b = DemAm(Root->pRight);
    if (Root->info < 0)
        return (a + b + 1);
    return (a + b);
}

// Ham tinh tong cac nut am
int TongAm(TREE Root)
{
    if (Root == NULL)
        return 0;
    int a = TongAm(Root->pLeft);
    int b = TongAm(Root->pRight);
    if (Root->info < 0)
        return (a + b + Root->info);
    return (a + b);
}

// Ham tinh trung binh cong cac so am trong cay
float TrungBinhCongAm(TREE Root)
{
    int s = TongAm(Root);
    int dem = DemAm(Root);
    if (dem == 0)
        return 0;
    return (float)s / dem;
}

// Ham tinh ty so R = a / b, voi a la tong cac nut duong va b la tong cac nut am
float TinhTySo(TREE Root)
{
    int a = TongDuong(Root);
    int b = TongAm(Root);
    if (b == 0)
        return 0; // Tranh chia cho 0
    return (float)a / b;
}

int main()
{
    // Du lieu dau vao
    int n = 21;
    int a[] = {1, 2, 9, 0, 0, 4, 0, 0, 7, 3, 6, 0, 0, 5, 0, 0, 8, 0, 10, 0, 0};
    int i = 0;
    TREE root;

    Init(root); // Khoi tao cay
    CreateTree(root, a, i, n); // Tao cay tu mang

    // Tinh toan va xuat ket qua
    cout << "Trung binh cong cac nut trong cay: " << TrungBinhCong(root) << endl;
    cout << "Trung binh cong cac nut duong trong cay: " << TrungBinhDuong(root) << endl;
    cout << "Trung binh cong cac nut am trong cay: " << TrungBinhCongAm(root) << endl;
    cout << "Ti so R = a/b (a = tong nut duong, b = tong nut am): " << TinhTySo(root) << endl;

    return 0;
}

