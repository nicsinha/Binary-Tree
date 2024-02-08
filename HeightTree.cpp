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

int height(Node* root) {

    if(root == NULL) {
        return 0;
    }

    return 1 + max(height(root->left),height(root->right));
}

pair<int,bool> check_balance(Node* root) {

    pair<int,bool> P;

    if(root == NULL) {
        P.first = 0;
        P.second = true;
        return P;
    }

    pair<int,bool> left = check_balance(root->left);
    pair<int,bool> right = check_balance(root->right);

    P.first = 1 + max(left.first,right.first);

    if(abs(left.first - right.first) <= 1 && left.second && right.second) {
        P.second = true;
    } else {
        P.second = false;
    }
    

    return P;

}

int find_diameter(Node* root,int &diameter) {

    if(root == NULL) {
        return 0;
    }

    int lh = find_diameter(root->left,diameter);
    int rh = find_diameter(root->right,diameter);

    diameter = max(diameter,lh+rh);
    return 1+max(lh,rh);
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    //root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    int diameter = 0;

    cout<<find_diameter(root,diameter);

    //cout<<height(root);

    // pair<int,bool> ans = check_balance(root);

    // cout<<"ans = "<<ans.second;

    return 0;

}