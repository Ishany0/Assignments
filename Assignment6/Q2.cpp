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
        n->next = n;
        return;
    }
    Node* last = head;
    while (last->next != head) last = last->next;
    last->next = n;
    n->next = head;
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
    if (!head) {
        cout << "List is empty\n";
        return 0;
    }
    cout << "Circular linked list values including head again:\n";
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << head->data << "\n";
    return 0;
}
