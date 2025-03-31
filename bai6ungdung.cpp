#include <iostream>
#include <algorithm>

using namespace std;

void sortEvenOdd(int arr[], int n) {
    int evens[n], odds[n], zeros[n];
    int evenCount = 0, oddCount = 0, zeroCount = 0;
    int result[n];

    // Tach so chan, le va 0
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            zeros[zeroCount++] = i;
        } else if (arr[i] % 2 == 0) {
            evens[evenCount++] = arr[i];
        } else {
            odds[oddCount++] = arr[i];
        }
    }

    // Sap xep so chan tang dan va so le giam dan
    sort(evens, evens + evenCount);
    sort(odds, odds + oddCount, greater<int>());

    // Gop mang
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < n; i++) {
        bool isZero = false;
        for (int j = 0; j < zeroCount; j++) {
            if (zeros[j] == i) {
                result[i] = 0;
                isZero = true;
                break;
            }
        }
        if (isZero) continue;
        if (arr[i] % 2 == 0) {
            result[i] = evens[evenIndex++];
        } else {
            result[i] = odds[oddIndex++];
        }
    }

    // Sao chep ket qua vao mang goc
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int arr[] = {5, 2, 8, 0, 1, 7, 4, 0, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortEvenOdd(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
