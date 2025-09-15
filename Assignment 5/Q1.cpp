#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int target, int value) {
        if (!head) return;
        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->data != target) {
            prev = curr;
            curr = curr->next;
        }
        if (curr) {
            Node* newNode = new Node{value, curr};
            prev->next = newNode;
        }
    }

    void insertAfter(int target, int value) {
        Node* curr = head;
        while (curr && curr->data != target)
            curr = curr->next;
        if (curr) {
            Node* newNode = new Node{value, curr->next};
            curr->next = newNode;
        }
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
    }

    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        if (curr) {
            prev->next = curr->next;
            delete curr;
        }
    }

    int search(int value) {
        Node* curr = head;
        int pos = 1;
        while (curr) {
            if (curr->data == value)
                return pos;
            curr = curr->next;
            pos++;
        }
        return -1;
    }

    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertBefore(target, value);
                break;
            case 4:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAfter(target, value);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                {
                    int pos = list.search(value);
                    if (pos != -1)
                        cout << "Node found at position " << pos << endl;
                    else
                        cout << "Node not found\n";
                }
                break;
            case 9:
                list.display();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
