#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Ham tao mang ngau nhien
void generateRandomArray(vector<int>& arr, int n) {
    srand(time(NULL));
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Ham sap xep chen (Insertion Sort)
void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = a[i];
        while (j >= 0 && a[j] > x) { // Loai bo 'cont'
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

// Ham sap xep chon (Selection Sort)
void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minValue = a[i]; // Doi ten bien
        int minPosition = i; // Doi ten bien
        for (int j = i + 1; j < n; j++) {
            if (minValue > a[j]) {
                minValue = a[j];
                minPosition = j;
            }
        }
        swap(a[i], a[minPosition]);
    }
}

// Ham sap xep noi bot (Bubble Sort)
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Ham in mang
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int n = 1000;
    vector<int> arr;

    // Tao mang ngau nhien
    generateRandomArray(arr, n);
    cout << "Mang ngau nhien:" << endl;
    printArray(arr);

    // Sap xep bang Insertion Sort
    vector<int> arrInsertion = arr;
    insertionSort(arrInsertion);
    cout << "Insertion Sort:" << endl;
    printArray(arrInsertion);

    // Sap xep bang Selection Sort
    vector<int> arrSelection = arr;
    selectionSort(arrSelection);
    cout << "Selection Sort:" << endl;
    printArray(arrSelection);

    // Sap xep bang Bubble Sort
    vector<int> arrBubble = arr;
    bubbleSort(arrBubble);
    cout << "Bubble Sort:" << endl;
    printArray(arrBubble);

    return 0;
}
