#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insertBST(root->left, key);
    else if (key > root->data) root->right = insertBST(root->right, key);
    return root;
}

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteBST(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data) root->left = deleteBST(root->left, key);
    else if (key > root->data) root->right = deleteBST(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* succ = minNode(root->right);
            root->data = succ->data;
            root->right = deleteBST(root->right, succ->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int choice;
    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Inorder display\n4. Max depth\n5. Min depth\n6. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) return 0;
        if (choice == 6) break;
        int key;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> key;
                root = insertBST(root, key);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> key;
                root = deleteBST(root, key);
                break;
            case 3:
                inorder(root);
                cout << "\n";
                break;
            case 4:
                cout << "Maximum depth: " << maxDepth(root) << "\n";
                break;
            case 5:
                cout << "Minimum depth: " << minDepth(root) << "\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
