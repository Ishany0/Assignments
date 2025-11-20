#include <bits/stdc++.h>
using namespace std;

void minMaxSelectionSort(vector<int> &a) {
    int n = a.size();
    int start = 0, end = n - 1;
    while (start < end) {
        int minIdx = start, maxIdx = start;
        for (int i = start; i <= end; i++) {
            if (a[i] < a[minIdx]) minIdx = i;
            if (a[i] > a[maxIdx]) maxIdx = i;
        }
        swap(a[start], a[minIdx]);
        if (maxIdx == start) maxIdx = minIdx;
        swap(a[end], a[maxIdx]);
        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    minMaxSelectionSort(a);
    cout << "Sorted array:\n";
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
