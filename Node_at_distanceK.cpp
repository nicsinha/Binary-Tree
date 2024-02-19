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

void findNodeAtDistanceK(Node* t, int k, vector<int> &ans, int l) {

    if(k == l) {
        cout<<"t->data = "<<t->data<<endl;
        ans.push_back(t->data);
        return;
    }
    if(t == NULL) {
        return;
    }
    if(t->left) findNodeAtDistanceK(t->left,k,ans,l+1);
    if(t->right) findNodeAtDistanceK(t->right,k,ans,l+1);

}

Node* findNode(Node* root,int key) {
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == key) {
        return root;
    }
    Node* left = findNode(root->left,key);
    Node* right = findNode(root->right,key);

    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else {
        return NULL;
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
    root->left->right->left = new Node(10);

    Node* t = findNode(root,2);

    cout<<"t = "<<t->data<<endl;

    int key = 2;
    vector<int> ans; 

    findNodeAtDistanceK(t,key,ans,0);

    for(auto &i:ans) {
        cout<<i<<" ";
    }
    

    
}