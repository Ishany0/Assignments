#include <bits/stdc++.h>
using namespace std;

struct PriorityQueue {
    vector<int> heap;
    void push(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] >= heap[i]) break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }
    int top() {
        if (heap.empty()) {
            cout << "Priority queue is empty\n";
            return INT_MIN;
        }
        return heap[0];
    }
    void pop() {
        if (heap.empty()) {
            cout << "Priority queue is empty\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        int n = heap.size();
        int i = 0;
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, largest = i;
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    bool empty() {
        return heap.empty();
    }
    void display() {
        if (heap.empty()) {
            cout << "Priority queue is empty\n";
            return;
        }
        cout << "Heap elements: ";
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;
    while (true) {
        cout << "\n1. Insert\n2. Get max\n3. Delete max\n4. Display heap\n5. Exit\n";
        int ch;
        cout << "Enter choice: ";
        if (!(cin >> ch)) return 0;
        if (ch == 5) break;
        int x;
        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                pq.push(x);
                break;
            case 2:
                x = pq.top();
                if (x != INT_MIN) cout << "Max element: " << x << "\n";
                break;
            case 3:
                pq.pop();
                break;
            case 4:
                pq.display();
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
