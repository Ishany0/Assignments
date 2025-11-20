#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
    Node(char d) : data(d), prev(nullptr), next(nullptr) {}
};

void insertEnd(Node* &head, char c) {
    Node* n = new Node(c);
    if (!head) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* left = head;
    Node* right = head;
    while (right->next) right = right->next;
    while (left != right && right->next != left) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter string:\n";
    getline(cin, s);
    if (s.size() == 0) getline(cin, s);
    Node* head = nullptr;
    for (char c : s) insertEnd(head, c);
    cout << (isPalindrome(head) ? "True\n" : "False\n");
    return 0;
}
