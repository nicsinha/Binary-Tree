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

int Findwidth(Node* root) {

    int ans;
    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty()) {

        int n = q.size();
        int left,right;
        int min = q.front().second;
        for(int i=0;i<n;i++) {

            auto temp = q.front();
            Node* node = temp.first;
            int index = temp.second - min;
            q.pop();

            if(i==0) {left = index;}
            if(i==n-1) {right = index;}

            if(node->left) q.push({root->left,2*index + 1});
            if(node->left) q.push({root->left,2*index + 1});
        }
        ans = max(ans, right - left);
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

    cout<<Findwidth(root);


    

}