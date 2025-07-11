#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert a new node in BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Find minimum value node in subtree
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node from BST
Node* deleteFromBST(Node* root, int val) {
    if (root == NULL) return NULL;

    if (val < root->data) {
        root->left = deleteFromBST(root->left, val);
    } else if (val > root->data) {
        root->right = deleteFromBST(root->right, val);
    } else {
        // Node to be deleted found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: Only left child
        else if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Only right child
        else if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 4: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteFromBST(root->right, temp->data);
        }
    }
    return root;
}

// Inorder traversal (sorted output)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int n, val;
    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    cout << "Enter value to delete: ";
    cin >> val;

    root = deleteFromBST(root, val);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
