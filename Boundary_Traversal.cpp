#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
bool isleaf(Node* node) {
    if(node->left == NULL && node->right == NULL) {
        return true;
    }
    return false;
}
void leftBoundary(Node* root) {

    Node* temp = root;

    while(temp) {
        if(!isleaf(temp)) {cout<<temp->data<<" ";}
        //cout<<temp->data<<" ";
        if(temp->left) {temp = temp->left;}
        else {temp = temp->right;}
    }
    cout<<endl;
}

void rightBoundary(Node* root) {
    
    Node* temp = root;

    while(temp) {
        if(!isleaf(temp)) {cout<<temp->data<<" ";}

        if(temp->right) {temp = temp->right;}
        else {temp = temp->left;}

    }
    cout<<endl;
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

    leftBoundary(root);
    rightBoundary(root);

}