#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insertLevelOrder(const vector<int> &a, int i) {
    if (i >= (int)a.size() || a[i] == -1) return nullptr;
    Node* root = new Node(a[i]);
    root->left = insertLevelOrder(a, 2 * i + 1);
    root->right = insertLevelOrder(a, 2 * i + 2);
    return root;
}

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    int n;
    cout << "Enter number of nodes including -1 for NULL in level order: ";
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    Node* root = insertLevelOrder(a, 0);
    cout << (isBST(root) ? "Tree is a BST\n" : "Tree is not a BST\n");
    return 0;
}
