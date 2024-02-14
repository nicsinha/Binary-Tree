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
bool findPath(Node* root, int target, vector<int> &path) {

    if(root == NULL) {
        return false;
    }
    path.push_back(root->data);

    if(root->data == target) {
        return true;
    }

    bool l = findPath(root->left,target,path);
    bool r = findPath(root->right,target,path);

    if(l || r) {
        return true;
    }

    path.pop_back();
    return false;
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

    vector<int> path;

    findPath(root,8,path);

    for(auto i:path) {
        cout<<i<<" ";
    }


    

}