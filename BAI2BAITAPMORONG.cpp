#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct Stack {
    Node* top;
};

// Khoi tao stack rong
void Init(Stack &s) {
    s.top = nullptr;
}

// Tao mot node moi
Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}

// Kiem tra stack rong
bool IsEmpty(Stack &s) {
    return s.top == nullptr;
}

// Them phan tu vao stack
void Push(Stack &s, int x) {
    Node* p = CreateNode(x);
    p->next = s.top;
    s.top = p;
}

// Lay phan tu ra khoi stack
int Pop(Stack &s) {
    if (!IsEmpty(s)) {
        Node* p = s.top;
        int x = p->info;
        s.top = p->next;
        delete p;
        return x;
    } else {
        cout << "Stack rong (empty stack)" << endl;
        return -1;  // Tra ve gia tri khong hop le
    }
}

// Xem phan tu tren cung cua stack
int Peek(Stack &s) {
    if (!IsEmpty(s)) {
        return s.top->info;
    } else {
        cout << "Stack rong (empty stack)" << endl;
        return -1;  // Tra ve gia tri khong hop le
    }
}

// Xoa tat ca phan tu trong stack
void Clear(Stack &s) {
    while (s.top != nullptr) {
        Node* p = s.top;
        s.top = s.top->next;
        delete p;
    }
}

int main() {
    Stack s;
    Init(s);  // Khoi tao stack

    Push(s, 10);
    Push(s, 20);
    Push(s, 30);

    cout << "Phan tu tren cung: " << Peek(s) << endl;

    cout << "Pop: " << Pop(s) << endl;

    cout << "Phan tu tren cung sau khi pop: " << Peek(s) << endl;

    Clear(s);
    cout << "Stack sau khi clear, phan tu tren cung: " << Peek(s) << endl;

    return 0;
}
