x#include <iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void iterativePreorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    stack<Node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        Node* currentNode = nodeStack.top();
        nodeStack.pop();

        cout << currentNode->val << " "; // Process the current node

        // Push the right node onto the stack before the left node, so the left node is processed first
        if (currentNode->right) {
            nodeStack.push(currentNode->right);
        }
        if (currentNode->left) {
            nodeStack.push(currentNode->left);
        }
    }
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Iterative Preorder Traversal: ";
    iterativePreorder(root);

    // Clean up memory (optional)
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

