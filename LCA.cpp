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

Node* LCA(Node* root, Node* p, Node* q) {

    if(root == NULL || root ==p || root==q) {
        return root;
    }

    Node* left = LCA(root->left,p,q);
    Node* right = LCA(root->right,p,q);

    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else {
        return root;
    }
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

    Node* result = LCA(root,root->left->right,root->left->left->right);

    cout<<result->data;


    

}