#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Insert into BST
Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

// In-order Traversal (left, root, right)
void inOrderTraversal(Node* root) {
    if (root == NULL) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Function to take input and build the BST
Node* takeInput() {
    Node* root = NULL;
    int data;
    cout << "Enter data to create BST (end with -1): ";
    while (cin >> data && data != -1) {
        root = insertIntoBST(root, data);
    }
    return root;
}

// Search a value in BST
bool searchInBST(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchInBST(root->left, key);
    return searchInBST(root->right, key);
}

int main() {
    Node* root = takeInput();

    cout << "In-order Traversal of BST: ";
    inOrderTraversal(root);
    cout << endl;

    // Optional: Search for a value
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    if (searchInBST(root, key)) {
        cout << key << " found in BST." << endl;
    } else {
        cout << key << " not found in BST." << endl;
    }

    return 0;
}
