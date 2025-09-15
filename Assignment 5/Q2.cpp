#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert node at the end
void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = newNode;
}

// Function to count and delete all occurrences of key
int countAndDelete(Node*& head, int key) {
    int count = 0;
    // Remove occurrences at the head
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    // Remove occurrences in the rest of the list
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data;
        if (head->next)
            std::cout << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example input: 1->2->1->2->1->3->1, key: 1
    Node* head = nullptr;
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int val : arr)
        append(head, val);

    int key = 1;
    std::cout << "Original Linked List: ";
    printList(head);

    int count = countAndDelete(head, key);

    std::cout << "Count: " << count << std::endl;
    std::cout << "Updated Linked List: ";
    printList(head);

    // Free remaining nodes
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
