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

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root && root->data != key) {
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* minNode(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* node) {
    if (!node) return nullptr;
    if (node->right) return minNode(node->right);
    Node* succ = nullptr;
    while (root) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* node) {
    if (!node) return nullptr;
    if (node->left) return maxNode(node->left);
    Node* pred = nullptr;
    while (root) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    if (!(cin >> n)) return 0;
    Node* root = nullptr;
    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }
    int key;
    cout << "Enter key to search: ";
    cin >> key;
    cout << (searchRec(root, key) ? "Found (recursive)\n" : "Not found (recursive)\n");
    cout << (searchIter(root, key) ? "Found (iterative)\n" : "Not found (iterative)\n");
    Node* mn = minNode(root);
    Node* mx = maxNode(root);
    if (mn) cout << "Minimum: " << mn->data << "\n";
    if (mx) cout << "Maximum: " << mx->data << "\n";
    cout << "Enter key to find inorder successor and predecessor: ";
    cin >> key;
    Node* node = searchIter(root, key);
    if (!node) {
        cout << "Key not in BST\n";
    } else {
        Node* succ = inorderSuccessor(root, node);
        Node* pred = inorderPredecessor(root, node);
        if (succ) cout << "Inorder successor: " << succ->data << "\n";
        else cout << "No inorder successor\n";
        if (pred) cout << "Inorder predecessor: " << pred->data << "\n";
        else cout << "No inorder predecessor\n";
    }
    return 0;
}
