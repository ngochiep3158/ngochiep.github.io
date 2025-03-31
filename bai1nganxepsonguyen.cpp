#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <cctype>
#include <cmath>

using namespace std;

// (a) StackInt (mang)
struct StackInt {
    int* arr;
    int top;
    int size;
    int count;
};

void Init(StackInt& s, int size = 5) {
    s.top = -1;
    s.count = 0;
    s.size = size;
    s.arr = new int[s.size];
}

void Delete(StackInt& s) {
    if (s.arr) {
        delete[] s.arr;
        s.arr = nullptr;
    }
    s.top = -1;
    s.count = 0;
    s.size = 0;
}

bool IsEmpty(const StackInt& s) {
    return s.top == -1;
}

bool IsFull(const StackInt& s) {
    return s.top == s.size - 1;
}

void Push(StackInt& s, int x) {
    if (!IsFull(s)) {
        s.top++;
        s.arr[s.top] = x;
        s.count++;
    } else {
        cout << "Stack bi tran (stack overflow)" << endl;
    }
}

int Pop(StackInt& s) {
    if (!IsEmpty(s)) {
        int x = s.arr[s.top];
        s.top--;
        s.count--;
        return x;
    } else {
        cout << "Stack rong (empty stack)" << endl;
        return -1;
    }
}

int Peek(const StackInt& s) {
    if (!IsEmpty(s)) {
        return s.arr[s.top];
    } else {
        cout << "Chong rong (empty stack)" << endl;
        return -1;
    }
}

void Clear(StackInt& s) {
    s.top = -1;
    s.count = 0;
}

// (a) LinkedStackInt (danh sach lien ket)
typedef struct node {
    int info;
    struct node* next;
} Node;

struct LinkedStackInt {
    Node* top;
    int count;
};

void Init(LinkedStackInt& s) {
    s.top = nullptr;
    s.count = 0;
}

Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}

bool IsEmpty(const LinkedStackInt& s) {
    return s.top == nullptr;
}

void Delete(LinkedStackInt& s) {
    while (s.top != nullptr) {
        Node* p = s.top;
        s.top = s.top->next;
        delete p;
    }
    s.count = 0;
}

void Push(LinkedStackInt& s, int x) {
    Node* p = CreateNode(x);
    p->next = s.top;
    s.top = p;
    s.count++;
}

int Pop(LinkedStackInt& s) {
    if (!IsEmpty(s)) {
        int x = s.top->info;
        Node* p = s.top;
        s.top = p->next;
        s.count--;
        delete p;
        return x;
    } else {
        cout << "Stack rong (empty stack)" << endl;
        return -1;
    }
}

int Peek(const LinkedStackInt& s) {
    if (!IsEmpty(s)) {
        return s.top->info;
    } else {
        cout << "Stack rong (empty stack)" << endl;
        return -1;
    }
}

void Clear(LinkedStackInt& s) {
    while (s.top != nullptr) {
        Node* p = s.top;
        s.top = s.top->next;
        delete p;
    }
    s.count = 0;
}

// (b) Ung dung ngan xep de dao so
void reverseNumber(int num) {
    StackInt s;
    Init(s, 20);

    while (num > 0) {
        Push(s, num % 10);
        num /= 10;
    }

    cout << "Reversed number: ";
    while (!IsEmpty(s)) {
        cout << Pop(s);
    }
    cout << endl;

    Delete(s);
}

// (c) Ung dung ngan xep de kiem tra xau doi xung (mo rong sang StackString)
struct StackString {
    string* arr;
    int top;
    int size;
    int count;
};

void Init(StackString& s, int size = 100) {
    s.top = -1;
    s.count = 0;
    s.size = size;
    s.arr = new string[s.size];
}

void Delete(StackString& s) {
    if (s.arr) {
        delete[] s.arr;
        s.arr = nullptr;
    }
    s.top = -1;
    s.count = 0;
    s.size = 0;
}

bool IsEmpty(const StackString& s) {
    return s.top == -1;
}

bool IsFull(const StackString& s) {
    return s.top == s.size - 1;
}

void Push(StackString& s, const string& str) {
    if (!IsFull(s)) {
        s.top++;
        s.arr[s.top] = str;
        s.count++;
    } else {
        cout << "Stack bi tran (stack overflow)" << endl;
    }
}

string Pop(StackString& s) {
    if (!IsEmpty(s)) {
        string str = s.arr[s.top];
        s.top--;
        s.count--;
        return str;
    } else {
        cout << "Stack rong (empty stack)" << endl;
        return "";
    }
}

bool isPalindrome(const string& str) {
    StackString s;
    Init(s, str.length());

    for (char c : str) {
        Push(s, string(1, c));
    }

    string reversedStr = "";
    while (!IsEmpty(s)) {
        reversedStr += Pop(s);
    }

    Delete(s);
    return str == reversedStr;
}

// (d) Ung dung ngan xep de doi tu so thap phan sang nhi phan
string decimalToBinary(int num) {
    StackInt s;
    Init(s, 32);

    while (num > 0) {
        Push(s, num % 2);
        num /= 2;
    }

    string binary = "";
    while (!IsEmpty(s)) {
        binary += to_string(Pop(s));
    }

    Delete(s);
    return binary;
}

// (e) Nhap mot bieu thuc tu ban phim, hay chuyen sang dang hau to va tinh gia tri bieu thuc.
int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

vector<string> infixToPostfix(const string& infix) {
    vector<string> postfix;
    stack<string> operators;
    stringstream ss(infix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            postfix.push_back(token);
        } else if (token == "(") {
            operators.push(token);
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        } else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            while (!operators.empty() && getPrecedence(operators.top()[0]) >= getPrecedence(token[0])) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
    	postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

double evaluatePostfix(const vector<string>& postfix) {
    stack<double> operands;

    for (const string& token : postfix) {
        if (isdigit(token[0])) {
            operands.push(stod(token));
        } else {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();
            if (token == "+") {
                operands.push(operand1 + operand2);
            } else if (token == "-") {
                operands.push(operand1 - operand2);
            } else if (token == "*") {
                operands.push(operand1 * operand2);
            } else if (token == "/") {
                operands.push(operand1 / operand2);
            } else if (token == "^") {
                operands.push(pow(operand1, operand2));
            }
        }
    }

    return operands.top();
}

int main() {
    // (a) Su dung StackInt (mang)
    StackInt stackIntArray;
    Init(stackIntArray);

    Push(stackIntArray, 10);
    Push(stackIntArray, 20);
    Push(stackIntArray, 30);

    cout << "StackInt (mang) Peek: " << Peek(stackIntArray) << endl;

    cout << "StackInt (mang) Pop: " << Pop(stackIntArray) << endl;

    Clear(stackIntArray);
    Delete(stackIntArray);

    // (a) Su dung LinkedStackInt (danh sach lien ket)
    LinkedStackInt linkedStackInt;
    Init(linkedStackInt);

    Push(linkedStackInt, 40);
    Push(linkedStackInt, 50);
    Push(linkedStackInt, 60);

    cout << "LinkedStackInt Peek: " << Peek(linkedStackInt) << endl;

    cout << "LinkedStackInt Pop: " << Pop(linkedStackInt) << endl;

    Clear(linkedStackInt);
    Delete(linkedStackInt);

    // (b) Dao so
    reverseNumber(12345);

    // (c) Kiem tra xau doi xung
    string palindrome1 = "madam";
    string palindrome2 = "hello";
    cout << palindrome1 << " la xau doi xung: " << isPalindrome(palindrome1) << endl;
    cout << palindrome2 << " la xau doi xung: " << isPalindrome(palindrome2) << endl;

    // (d) Doi thap phan sang nhi phan
    cout << "So thap phan 10 sang nhi phan: " << decimalToBinary(10) << endl;

    // (e) Tinh gia tri bieu thuc hau to
    string infixExpression = "( 1 + 2 ) * 4 + 3";
    vector<string> postfixExpression = infixToPostfix(infixExpression);
    cout << "Bieu thuc hau to: ";
    for (const string& token : postfixExpression) {
        cout << token << " ";
    }
    cout << endl;
    cout << "Ket qua: " << evaluatePostfix(postfixExpression) << endl;

    return 0;
}
