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

Node* BuildTreeHelper(vector<int> Inorder,int l,int r,vector<int> Postorder,int s,int e,unordered_map<int,int> mp) {

    if(l > r || s > e) {return NULL;}
    Node* root = new Node(Postorder[e]);

    int index = mp[Postorder[e]];

    int len = index - l;

    root->left = BuildTreeHelper(Inorder,l,index-1,Postorder,s,s+len-1,mp);

    root->right = BuildTreeHelper(Inorder,index+1,r,Postorder,s+len,e-1,mp);

    return root;


}

Node* BuildTree(vector<int> Inorder, vector<int> Postorder) {

    int n = Inorder.size();
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++) {
        mp[Inorder[i]] = i;
    }

   Node* root = BuildTreeHelper(Inorder,0,Inorder.size()-1,Postorder,0,Postorder.size()-1,mp);
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

    vector<int> Inorder = {40,20,50,10,60,30};
    vector<int> Postorder = {40,50,20,60,30,10};

    Node* root = BuildTree(Inorder,Postorder);

    inorder(root);

}
