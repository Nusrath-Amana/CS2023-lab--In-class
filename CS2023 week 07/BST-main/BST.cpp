#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        node = new struct node;
        node->key = key;
        node->left = node->right = NULL;
        return node;
    }

    // otherwise recur down the tree
    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else {
        node->right = insertNode(node->right, key);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) {
        return root;
    }

    // Recur down the tree
    if (key < root->key) {
        //key lies in left subtree
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        //key lies in right subtree
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *current = root->right;
        while (current->left != NULL) {
            current = current->left;
        }

        // Copy the inorder successor's content to this node
        root->key = current->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, current->key);
    }

    // Return the unchanged node pointer
    return root;
}

// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }

    traverseInOrder(root);
    return 0;
}
