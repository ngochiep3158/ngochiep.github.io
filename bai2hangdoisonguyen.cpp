#include <iostream>
#include <string>
#include <vector>

using namespace std;

// (a) QueueInt (mang)
struct QueueInt {
    int front;
    int rear;
    int count;
    int size;
    int* arr;
};

void Init(QueueInt& q, int size) {
    q.front = q.rear = -1;
    q.count = 0;
    q.size = size;
    q.arr = new int[q.size];
}

void Delete(QueueInt& q) {
    if (q.arr) {
        delete[] q.arr;
        q.arr = nullptr;
    }
    q.front = q.rear = -1;
    q.count = 0;
    q.size = 0;
}

bool IsEmpty(const QueueInt& q) {
    return q.front == -1;
}

bool IsFull(const QueueInt& q) {
    return (q.rear - q.front + 1 == 0) || (q.rear - q.front + 1 == q.size);
}

void Enqueue(QueueInt& q, int x) {
    if (q.front == -1) {
        q.front = 0;
    }
    q.rear++;
    if (q.rear == q.size) {
        q.rear = 0;
    }
    q.arr[q.rear] = x;
    q.count++;
}

int Dequeue(QueueInt& q) {
    int x = q.arr[q.front];
    if (q.front == q.rear) {
        q.front = -1;
        q.rear = -1;
    } else {
        q.front++;
        if (q.front == q.size) {
            q.front = 0;
        }
    }
    q.count--;
    return x;
}

int Peek(const QueueInt& q) {
    return q.arr[q.front];
}

void Clear(QueueInt& q) {
    q.front = q.rear = -1;
    q.count = 0;
}

// (a) LinkedQueueInt (danh sach lien ket)
typedef struct node {
    int info;
    struct node* next;
} Node;

struct LinkedQueueInt {
    Node* front;
    Node* rear;
    int count;
};

void Init(LinkedQueueInt& q) {
    q.front = q.rear = nullptr;
    q.count = 0;
}

Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void Delete(LinkedQueueInt& q) {
    while (q.front != nullptr) {
        Node* p = q.front;
        q.front = q.front->next;
        delete p;
    }
    q.count = 0;
}

void Enqueue(LinkedQueueInt& q, int x) {
    Node* p = CreateNode(x);
    if (q.front == nullptr) {
        q.front = p;
    } else {
        q.rear->next = p;
    }
    q.rear = p;
    q.count++;
}

int Dequeue(LinkedQueueInt& q) {
    Node* p = q.front;
    int x = p->info;
    q.front = p->next;
    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    delete p;
    q.count--;
    return x;
}

int Peek(const LinkedQueueInt& q) {
    return q.front->info;
}

void Clear(LinkedQueueInt& q) {
    Node* p = q.front;
    while (p != nullptr) {
        Node* t = p;
        p = p->next;
        delete t;
    }
    q.front = q.rear = nullptr;
    q.count = 0;
}

// (b) Ung dung hang doi de lam bai toan xep lich cap mua nam/nu
struct Dancer {
    string Name;
    string Sex;
};

struct QueueDancer {
    int front;
    int rear;
    int count;
    int size;
    Dancer* arr;
};

void Init(QueueDancer& q, int size) {
    q.front = q.rear = -1;
    q.count = 0;
    q.size = size;
    q.arr = new Dancer[q.size];
}

void Delete(QueueDancer& q) {
    if (q.arr) {
        delete[] q.arr;
        q.arr = nullptr;
    }
    q.front = q.rear = -1;
    q.count = 0;
    q.size = 0;
}

bool IsEmpty(const QueueDancer& q) {
    return q.front == -1;
}

bool IsFull(const QueueDancer& q) {
    return (q.rear - q.front + 1 == 0) || (q.rear - q.front + 1 == q.size);
}

void Enqueue(QueueDancer& q, const Dancer& x) {
    if (q.front == -1) {
        q.front = 0;
    }
    q.rear++;
    if (q.rear == q.size) {
        q.rear = 0;
    }
    q.arr[q.rear] = x;
    q.count++;
}

Dancer Dequeue(QueueDancer& q) {
    Dancer x = q.arr[q.front];
    if (q.front == q.rear) {
        q.front = -1;
        q.rear = -1;
    } else {
        q.front++;
        if (q.front == q.size) {
            q.front = 0;
        }
    }
    q.count--;
    return x;
}

Dancer Peek(const QueueDancer& q) {
    return q.arr[q.front];
}

void Clear(QueueDancer& q) {
    q.front = q.rear = -1;
    q.count = 0;
}

void GetName(Dancer& d, const string& s) {
    d.Name = s;
}

string ToString(Dancer& d) {
    return d.Name;
}

void NewDancers(QueueDancer& male, QueueDancer& female) {
    if (male.count > 0 && female.count > 0) {
        Dancer m = Dequeue(male);
        Dancer w = Dequeue(female);
        cout << "Cap dien vien: " << m.Name << " va " << w.Name << endl;
    } else if (male.count > 0 && female.count == 0) {
        cout << "Dang cho dien vien nu." << endl;
    } else if (female.count > 0 && male.count == 0) {
        cout << "Dang cho dien vien nam." << endl;
    }
}

void HeadOfLine(QueueDancer& male, QueueDancer& female) {
    if (male.count > 0 && female.count > 0) {
        cout << "Cap dien vien ke tiep: " << Peek(male).Name << "\t" << Peek(female).Name << endl;
    } else if (male.count > 0) {
        cout << "Dien vien nam ke tiep: " << Peek(male).Name << endl;
    } else if (female.count > 0) {
        cout << "Dien vien nu ke tiep: " << Peek(female).Name << endl;
    }
}

void StartDancing(QueueDancer& male, QueueDancer& female) {
    cout << "Cac cap dien vien:" << endl;
    while (male.count > 0 && female.count > 0) {
        Dancer m = Dequeue(male);
        Dancer w = Dequeue(female);
        cout << m.Name << "\t" << w.Name << endl;
    }
}

void ShowQueue(QueueDancer& q) {
    QueueDancer temp;
    Init(temp, q.size);
    while (!IsEmpty(q)) {
        Dancer d = Dequeue(q);
        cout << d.Name << endl;
        Enqueue(temp, d);
    }
    // Sao chep lai cac phan tu tu temp vao q
    while (!IsEmpty(temp)) {
        Dancer d = Dequeue(temp);
        Enqueue(q, d);
    }
    Delete(temp);
}

void FormLines(QueueDancer& male, QueueDancer& female) {
    Dancer dancers[] = {{"F Trang", "F"}, {"M Truc", "M"}, {"M Thien", "M"}, {"M Bao", "M"}, {"F Thu", "F"}, {"M Tien", "M"}, {"F Thuy", "F"}, {"M Nghia", "M"}, {"F Thao", "F"}, {"M Phuoc", "M"}, {"M Hung", "M"}, {"F Vy", "F"}};
    int n = 12;
    for (int i = 0; i < n; i++) {
        if (dancers[i].Sex == "M") {
            Enqueue(male, dancers[i]);
        } else {
            Enqueue(female, dancers[i]);
        }
    }
}

// (c) Ung dung hang doi de cai thuat toan RadixSort
enum DigitType { ONES = 1, TENS = 10 };

void DisplayArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void RadixSort(QueueInt bin[], int a[], int n, int digit) {
    for (int i = 0; i < n; i++) {
        int snum;
        if (digit == ONES) {
            snum = a[i] % 10;
        } else {
            snum = a[i] / 10;
        }
        Enqueue(bin[snum], a[i]);
    }
}

void BuildArray(QueueInt bin[], int a[], int& n) {
    n = 0;
    for (int i = 0; i <= 9; i++) {
        while (bin[i].count > 0) {
            a[n] = Dequeue(bin[i]);
            n++;
        }
    }
}

int main() {
    // (a) Su dung QueueInt (mang)
    QueueInt queueIntArray;
    Init(queueIntArray, 5);

    Enqueue(queueIntArray, 10);
    Enqueue(queueIntArray, 20);
    Enqueue(queueIntArray, 30);

    cout << "QueueInt (mang) Peek: " << Peek(queueIntArray) << endl;

    cout << "QueueInt (mang) Dequeue: " << Dequeue(queueIntArray) << endl;

    Clear(queueIntArray);
    Delete(queueIntArray);

    // (a) Su dung LinkedQueueInt (danh sach lien ket)
    LinkedQueueInt linkedQueueInt;
    Init(linkedQueueInt);

    Enqueue(linkedQueueInt, 40);
    Enqueue(linkedQueueInt, 50);
    Enqueue(linkedQueueInt, 60);

    cout << "LinkedQueueInt Peek: " << Peek(linkedQueueInt) << endl;

    cout << "LinkedQueueInt Dequeue: " << Dequeue(linkedQueueInt) << endl;

    Clear(linkedQueueInt);
    Delete(linkedQueueInt);

    // (b) Xep lich cap mua nam/nu
    QueueDancer males;
    Init(males, 12);
    QueueDancer females;
    Init(females, 12);

    FormLines(males, females);

    cout << "Danh sach dien vien nam:" << endl;
    ShowQueue(males);
    cout << "Danh sach dien vien nu:" << endl;
    ShowQueue(females);

    cout << "Cac cap dien vien:" << endl;
    StartDancing(males, females);

    cout << endl;
    if (males.count > 0 || females.count > 0) {
        HeadOfLine(males, females);
    }
    NewDancers(males, females);

    cout << endl;
    if (males.count > 0 || females.count > 0) {
        HeadOfLine(males, females);
    }
    NewDancers(males, females);

    Delete(males);
    Delete(females);

    // (c) RadixSort
    int nums[] = {91, 46, 85, 15, 92, 35, 31, 22};
    int n = sizeof(nums) / sizeof(nums[0]);
    QueueInt numQueue[10];

    for (int i = 0; i < 10; i++) {
        Init(numQueue[i], n);
    }

    cout << "Day ban dau: ";
    DisplayArray(nums, n);
    cout << endl;

    RadixSort(numQueue, nums, n, ONES);
    BuildArray(numQueue, nums, n);

    cout << "Ket qua buoc 1: ";
    DisplayArray(nums, n);
    cout << endl;

    RadixSort(numQueue, nums, n, TENS);
    BuildArray(numQueue, nums, n);

    cout << "Ket qua buoc 2: ";
    DisplayArray(nums, n);
    cout << endl;

    for (int i = 0; i < 10; i++) {
        Delete(numQueue[i]);
    }

    return 0;
}
