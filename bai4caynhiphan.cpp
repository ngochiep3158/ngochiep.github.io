#include <iostream>

using namespace std;

// Dinh nghia cau truc cay nhi phan tim kiem
struct node {
    int info;
    struct node *pLeft;
    struct node *pRight;
};

typedef struct node NODE;
typedef NODE* TREE;

// Ham khoi tao cay
void Init(TREE &Root) {
    Root = NULL;
}

// Ham tao mot nut moi
NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Ham them mot phan tu vao BST
void InsertNode(TREE &Root, int x) {
    if (Root == NULL) {
        Root = CreateNode(x);
        return;
    }
    if (x < Root->info) {
        InsertNode(Root->pLeft, x);
    } else {
        InsertNode(Root->pRight, x);
    }
}

// Ham tim phan tu nho nhat trong cay
NODE* NhoNhat(TREE Root) {
    if (Root == NULL) return NULL;
    NODE* lc = Root;
    while (lc->pLeft) {
        lc = lc->pLeft;
    }
    return lc;
}

// Ham tim phan tu lon nhat trong cay
NODE* LonNhat(TREE Root) {
    if (Root == NULL) return NULL;
    NODE* lc = Root;
    while (lc->pRight) {
        lc = lc->pRight;
    }
    return lc;
}

// Chuong trinh chinh
int main() {
    TREE Root;
    Init(Root);
    
    int a[] = {10, 5, 15, 3, 9, 12, 18, 7, 20}; // Du lieu dau vao
    int n = sizeof(a) / sizeof(a[0]);
    
    // Xay dung cay BST tu mang a[]
    for (int i = 0; i < n; i++) {
        InsertNode(Root, a[i]);
    }

    // Tim va in ra phan tu nho nhat
    NODE* minNode = NhoNhat(Root);
    if (minNode) {
        cout << "Phan tu nho nhat: " << minNode->info << endl;
    } else {
        cout << "Cay rong!" << endl;
    }

    // Tim va in ra phan tu lon nhat
    NODE* maxNode = LonNhat(Root);
    if (maxNode) {
        cout << "Phan tu lon nhat: " << maxNode->info << endl;
    } else {
        cout << "Cay rong!" << endl;
    }

    return 0;
}

