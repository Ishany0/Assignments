#include <iostream>
#include <queue>
using namespace std;

// (a) Stack using Two Queues
class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (!q1.empty()) q1.pop();
    }
    int top() {
        if (!q1.empty()) return q1.front();
        throw runtime_error("Stack is empty");
    }
    bool empty() {
        return q1.empty();
    }
};

// (b) Stack using One Queue
class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() {
        if (!q.empty()) return q.front();
        throw runtime_error("Stack is empty");
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackTwoQueues s2q;
    s2q.push(1);
    s2q.push(2);
    s2q.push(3);
    cout << "Stack using Two Queues: ";
    while (!s2q.empty()) {
        cout << s2q.top() << " ";
        s2q.pop();
    }
    cout << endl;

    StackOneQueue s1q;
    s1q.push(1);
    s1q.push(2);
    s1q.push(3);
    cout << "Stack using One Queue: ";
    while (!s1q.empty()) {
        cout << s1q.top() << " ";
        s1q.pop();
    }
    cout << endl;
    return 0;
}
