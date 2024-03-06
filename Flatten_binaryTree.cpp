#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;

    }
};

void flatten_tree(Node* root,Node* &prev) {

    if(root == NULL) {
        return;
    }

    flatten_tree(root->right,prev);
    flatten_tree(root->left,prev);

    root->right = prev;
    root->left = NULL;

    prev = root;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->right;
    }
    cout << endl;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    Node* prev = NULL;
    flatten_tree(root,prev);
    cout << "Flattened tree: ";
    printList(root);
    

}
