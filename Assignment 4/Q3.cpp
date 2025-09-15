#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even." << endl;
        return;
    }
    queue<int> firstHalf;
    int half = n / 2;

    // Move first half to a separate queue
    for (int i = 0; i < half; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Interleave elements
    while (!firstHalf.empty()) {
        cout << firstHalf.front() << " ";
        firstHalf.pop();
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; ++i)
        q.push(arr[i]);

    interleaveQueue(q);
    return 0;
}
