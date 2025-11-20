#include <bits/stdc++.h>
using namespace std;

struct DLLNode {
    int data;
    DLLNode *prev, *next;
    DLLNode(int d) : data(d), prev(nullptr), next(nullptr) {}
};

struct CLLNode {
    int data;
    CLLNode *next;
    CLLNode(int d) : data(d), next(nullptr) {}
};

void dllInsertEnd(DLLNode* &head, int val) {
    DLLNode* n = new DLLNode(val);
    if (!head) {
        head = n;
        return;
    }
    DLLNode* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void cllInsertEnd(CLLNode* &head, int val) {
    CLLNode* n = new CLLNode(val);
    if (!head) {
        head = n;
        n->next = n;
        return;
    }
    CLLNode* last = head;
    while (last->next != head) last = last->next;
    last->next = n;
    n->next = head;
}

int dllSize(DLLNode* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

int cllSize(CLLNode* head) {
    if (!head) return 0;
    int cnt = 0;
    CLLNode* curr = head;
    do {
        cnt++;
        curr = curr->next;
    } while (curr != head);
    return cnt;
}

int main() {
    int nd, nc;
    cout << "Enter number of DLL nodes: ";
    if (!(cin >> nd)) return 0;
    DLLNode* dhead = nullptr;
    cout << "Enter DLL elements:\n";
    for (int i = 0; i < nd; i++) {
        int x;
        cin >> x;
        dllInsertEnd(dhead, x);
    }
    cout << "Size of DLL: " << dllSize(dhead) << "\n";
    cout << "Enter number of CLL nodes: ";
    cin >> nc;
    CLLNode* chead = nullptr;
    cout << "Enter CLL elements:\n";
    for (int i = 0; i < nc; i++) {
        int x;
        cin >> x;
        cllInsertEnd(chead, x);
    }
    cout << "Size of CLL: " << cllSize(chead) << "\n";
    return 0;
}
