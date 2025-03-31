#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// a. Ham tim mang nghich the cua mot hoan vi
vector<int> findInversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                b[i]++;
            }
        }
    }
    return b;
}

// b. Ham tim hoan vi cua mot mang nghich the (neu co)
vector<int> findPermutation(vector<int>& inversions) {
    int n = inversions.size();
    list<int> resultList;
    vector<int> result;

    for (int i = n - 1; i >= 0; --i) {
        auto it = resultList.begin();
        advance(it, inversions[i]);
        resultList.insert(it, i + 1);
    }

    result.assign(resultList.begin(), resultList.end());
    return result;
}

int main() {
    // Vi du a: Tim mang nghich the
    vector<int> a = {5, 9, 1, 8, 2, 6, 4, 7, 3};
    vector<int> b = findInversions(a);

    cout << "Mang A: ";
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Mang nghich the B: ";
    for (int num : b) {
        cout << num << " ";
    }
    cout << endl;

    // Vi du b: Tim hoan vi tu mang nghich the
    vector<int> inversions = {2, 3, 6, 4, 0, 2, 2, 1, 0};
    vector<int> permutation = findPermutation(inversions);

    cout << "Mang nghich the: ";
    for (int num : inversions) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Hoan vi tu mang nghich the: ";
    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
