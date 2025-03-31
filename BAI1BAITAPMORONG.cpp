#include <iostream>
using namespace std;

struct Stack {
    int top;  // chi so cua phan tu tren cung
    int size;  // kich thuoc toi da cua stack
    int* arr;  // mang luu tru phan tu trong stack
};

// Khoi tao stack
void Init(Stack &s, int size) {
    s.top = -1;
    s.size = size;
    s.arr = new int[s.size];
}

// Huy stack
void Delete(Stack &s) {
    delete[] s.arr;
    s.top = -1;
    s.size = 0;
}

// Kiem tra stack rong
bool IsEmpty(Stack &s) {
    return s.top == -1;
}

// Kiem tra stack day
bool IsFull(Stack &s) {
    return s.top == s.size - 1;
}

// Them phan tu vao stack
void Push(Stack &s, int x) {
    if (!IsFull(s)) {
        s.top++;
        s.arr[s.top] = x;
    } else {
        cout << "Stack day (overflow)" << endl;
    }
}

// Lay phan tu ra khoi stack
int Pop(Stack &s) {
    if (!IsEmpty(s)) {
        int x = s.arr[s.top];
        s.top--;
        return x;
    } else {
        cout << "Stack rong (underflow)" << endl;
        return -1;  // Tra ve gia tri khong hop le
    }
}

// Xem phan tu tren cung cua stack
int Peek(Stack &s) {
    if (!IsEmpty(s)) {
        return s.arr[s.top];
    } else {
        cout << "Stack rong (empty stack)" << endl;
        return -1;  // Tra ve gia tri khong hop le
    }
}

int main() {
    Stack s;
    Init(s, 5);  // Khoi tao stack voi toi da 5 phan tu

    Push(s, 10);
    Push(s, 20);
    Push(s, 30);

    cout << "Phan tu tren cung: " << Peek(s) << endl;

    cout << "Pop: " << Pop(s) << endl;

    cout << "Phan tu tren cung sau khi pop: " << Peek(s) << endl;

    Delete(s);  // Huy stack
    return 0;
}
