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

Node* BuildTreeHelper(vector<int> Inorder,int l,int r,vector<int> PreOrder,int s,int e,unordered_map<int,int> mp) {

    if(l > r || s>e) {return NULL;}
    Node* root = new Node(PreOrder[s]);

    int index = mp[PreOrder[s]];

    int len = index - l;

    root->left = BuildTreeHelper(Inorder,l,index-1,PreOrder,s+1,s+l,mp);

    root->right = BuildTreeHelper(Inorder,index+1,r,PreOrder,s+len+1,e,mp);

    return root;


}

Node* BuildTree(vector<int> Inorder, vector<int> PreOrder) {

    int n = Inorder.size();
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++) {
        mp[Inorder[i]] = i;
    }

   Node* root = BuildTreeHelper(Inorder,0,Inorder.size()-1,PreOrder,0,PreOrder.size()-1,mp);
   return root;
}
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {

    vector<int> Inorder = {9,3,15,20,7};
    vector<int> Prerder = {3,9,20,15,7};

    Node* root = BuildTree(Inorder,Prerder);

    inorder(root);

}
