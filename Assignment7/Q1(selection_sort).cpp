#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx]) minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    selectionSort(a);
    cout << "Sorted array:\n";
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
