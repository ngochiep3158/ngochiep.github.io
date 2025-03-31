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
void Init(TREE &t) {
    t = NULL;
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
void InsertNode(TREE &t, int x) {
    if (t == NULL) {
        t = CreateNode(x);
        return;
    }
    if (x < t->info) {
        InsertNode(t->pLeft, x);
    } else {
        InsertNode(t->pRight, x);
    }
}

// Ham de quy dem so nut co mot con
int DemMotCon(TREE t) {
    if (t == NULL) return 0;
    if ((t->pLeft && !t->pRight) || (!t->pLeft && t->pRight)) {
        return 1 + DemMotCon(t->pLeft) + DemMotCon(t->pRight);
    }
    return DemMotCon(t->pLeft) + DemMotCon(t->pRight);
}

// Chuong trinh chinh
int main() {
    TREE t;
    Init(t);
    
    int a[] = {10, 5, 15, 3, 9, 12, 18, 7, 20}; // Du lieu dau vao
    int n = sizeof(a) / sizeof(a[0]);
    
    // Xay dung cay BST tu mang a[]
    for (int i = 0; i < n; i++) {
        InsertNode(t, a[i]);
    }

    // Dem so nut co mot con
    cout << "So nut co mot con: " << DemMotCon(t) << endl;

    return 0;
}

