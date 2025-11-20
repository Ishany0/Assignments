#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a) {
    int n = a.size();
    bool swapped = true;
    for (int i = 0; i < n - 1 && swapped; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    bubbleSort(a);
    cout << "Sorted array:\n";
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
