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

void leftview(Node* root) {

    queue<Node*> q;
    q.push(root);
    vector<int> v;
    while(!q.empty()) {

        int n = q.size();
        for(int i=0;i<n;i++) {
            Node* temp = q.front();
            q.pop();
            if(i==0) {v.push_back(temp->data);}
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}

        }
    }
    for(auto i:v){cout<<i<<" ";}
    cout<<endl;
}



int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(8);

    leftview(root);

}