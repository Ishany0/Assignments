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

void dllInsert(DLLNode* &head, int val, int pos) {
    DLLNode* n = new DLLNode(val);
    if (pos == 0 || !head) {
        n->next = head;
        if (head) head->prev = n;
        head = n;
        return;
    }
    DLLNode* curr = head;
    for (int i = 0; i < pos - 1 && curr->next; i++) curr = curr->next;
    n->next = curr->next;
    n->prev = curr;
    if (curr->next) curr->next->prev = n;
    curr->next = n;
}

void dllDelete(DLLNode* &head, int key) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    DLLNode* curr = head;
    while (curr && curr->data != key) curr = curr->next;
    if (!curr) {
        cout << "Key not found\n";
        return;
    }
    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    delete curr;
}

DLLNode* dllSearch(DLLNode* head, int key) {
    while (head) {
        if (head->data == key) return head;
        head = head->next;
    }
    return nullptr;
}

void dllDisplay(DLLNode* head) {
    if (!head) {
        cout << "DLL is empty\n";
        return;
    }
    cout << "DLL: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void cllInsert(CLLNode* &head, int val, int pos) {
    CLLNode* n = new CLLNode(val);
    if (!head) {
        head = n;
        n->next = n;
        return;
    }
    if (pos == 0) {
        CLLNode* last = head;
        while (last->next != head) last = last->next;
        n->next = head;
        last->next = n;
        head = n;
        return;
    }
    CLLNode* curr = head;
    for (int i = 0; i < pos - 1 && curr->next != head; i++) curr = curr->next;
    n->next = curr->next;
    curr->next = n;
}

void cllDelete(CLLNode* &head, int key) {
    if (!head) {
        cout << "CLL is empty\n";
        return;
    }
    CLLNode* curr = head;
    CLLNode* prev = nullptr;
    do {
        if (curr->data == key) break;
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    if (curr->data != key) {
        cout << "Key not found\n";
        return;
    }
    if (curr == head && curr->next == head) {
        delete curr;
        head = nullptr;
        return;
    }
    if (curr == head) {
        CLLNode* last = head;
        while (last->next != head) last = last->next;
        head = head->next;
        last->next = head;
        delete curr;
    } else {
        prev->next = curr->next;
        delete curr;
    }
}

CLLNode* cllSearch(CLLNode* head, int key) {
    if (!head) return nullptr;
    CLLNode* curr = head;
    do {
        if (curr->data == key) return curr;
        curr = curr->next;
    } while (curr != head);
    return nullptr;
}

void cllDisplay(CLLNode* head) {
    if (!head) {
        cout << "CLL is empty\n";
        return;
    }
    cout << "CLL: ";
    CLLNode* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << "\n";
}

int main() {
    DLLNode* dhead = nullptr;
    CLLNode* chead = nullptr;
    while (true) {
        cout << "\n1. DLL Insert\n2. DLL Delete\n3. DLL Search\n4. DLL Display\n5. CLL Insert\n6. CLL Delete\n7. CLL Search\n8. CLL Display\n9. Exit\n";
        int ch;
        cout << "Enter choice: ";
        if (!(cin >> ch)) return 0;
        if (ch == 9) break;
        int val, pos, key;
        switch (ch) {
            case 1:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                dllInsert(dhead, val, pos);
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                dllDelete(dhead, key);
                break;
            case 3:
                cout << "Enter key: ";
                cin >> key;
                if (dllSearch(dhead, key)) cout << "Found\n"; else cout << "Not found\n";
                break;
            case 4:
                dllDisplay(dhead);
                break;
            case 5:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                cllInsert(chead, val, pos);
                break;
            case 6:
                cout << "Enter key: ";
                cin >> key;
                cllDelete(chead, key);
                break;
            case 7:
                cout << "Enter key: ";
                cin >> key;
                if (cllSearch(chead, key)) cout << "Found\n"; else cout << "Not found\n";
                break;
            case 8:
                cllDisplay(chead);
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
