#include <iostream>

using namespace std;

void sortEvenOdd(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < right && arr[left] % 2 == 0) {
            left++;
        }
        while (left < right && arr[right] % 2 != 0) {
            right--;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortEvenOdd(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
