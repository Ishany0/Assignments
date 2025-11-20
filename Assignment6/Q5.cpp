#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

void insertEnd(Node* &head, int val) {
    Node* n = new Node(val);
    if (!head) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head) temp = temp->next;
    return temp == head;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    if (!(cin >> n)) return 0;
    Node* head = nullptr;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertEnd(head, x);
    }
    char makeCircular;
    cout << "Make list circular? (y/n): ";
    cin >> makeCircular;
    if (makeCircular == 'y' || makeCircular == 'Y') {
        if (head) {
            Node* t = head;
            while (t->next) t = t->next;
            t->next = head;
        }
    }
    cout << (isCircular(head) ? "True\n" : "False\n");
    return 0;
}
