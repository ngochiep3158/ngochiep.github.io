#include <iostream>

using namespace std;

// Dinh nghia cau truc Node
typedef struct node {
    int info;
    struct node *left;
    struct node *right;
} Node;

typedef Node* Tree;

// Ham khoi tao cay
void Init(Tree &t) {
    t = NULL;
}

// Ham tao mot nut moi
Node* CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL) return NULL;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Ham tao cay nhi phan tu mang a[]
void CreateTree(Tree &t, int a[], int &i, int n) {
    if (i >= n) return;
    
    if (a[i] == 0) {
        t = NULL; // Gap gia tri 0 thi gan NULL
    } else {
        t = CreateNode(a[i]); // Tao nut moi
        i++; // Tang chi so de duyet phan tu tiep theo
        CreateTree(t->left, a, i, n); // Xay dung cay con trai
        i++; // Tang chi so tiep
        CreateTree(t->right, a, i, n); // Xay dung cay con phai
    }
}

// Ham tim nut co gia tri x trong cay
Tree FindNode(Tree t, int x) {
    if (t == NULL) return NULL;
    if (t->info == x) return t;
    
    Tree left = FindNode(t->left, x);
    if (left != NULL) return left;
    
    return FindNode(t->right, x);
}

// Ham hoan doi cay tai nut co gia tri x
void SwapSubTree(Tree &t, int x) {
    Tree p = FindNode(t, x);
    if (p == NULL) return;

    // Thuc hien hoan doi nhu trong hinh
    Node *temp = p->left;
    p->left = p->right;
    p->right = temp;

    temp = p->left->left;
    p->left->left = p->left->right;
    p->left->right = temp;
}

// Ham duyet LNR de kiem tra cay
void Inorder(Tree t) {
    if (t == NULL) return;
    Inorder(t->left);
    cout << t->info << " ";
    Inorder(t->right);
}

// Chuong trinh chinh
int main() {
    int n = 21;
    int a[] = {10, 5, 9, 0, 0, 15, 12, 0, 0, 18, 20, 0, 0, 19, 0, 0, 3, 13, 0, 0, 7};
    int i = 0;
    Tree root;
    
    // Tao cay tu mang
    CreateTree(root, a, i, n);

    // In cay truoc khi hoan doi
    cout << "Cay truoc khi hoan doi: ";
    Inorder(root);
    cout << endl;

    // Hoan doi cay tai nut 10
    SwapSubTree(root, 10);

    // In cay sau khi hoan doi
    cout << "Cay sau khi hoan doi: ";
    Inorder(root);
    cout << endl;

    return 0;
}

