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

void topview(Node* root) {

    map<int,int> mp;
    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty()) {

        auto temp = q.front();
        q.pop();

        Node* node = temp.first;
        int line = temp.second;

        if(mp.find(line) == mp.end()) {
            mp[line] = node->data;
        }
        if(node->left) {
            q.push({node->left,line-1});
        }
        if(node->right) {
            q.push({node->right,line+1});
        }

    }
    for(auto i:mp) cout<<i.second<<" ";
    cout<<endl;

}
void downview(Node* root) {

    map<int,int> mp;
    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty()) {

        auto temp = q.front();
        q.pop();

        Node* node = temp.first;
        int line = temp.second;

        mp[line] = node->data;
        
        if(node->left) {
            q.push({node->left,line-1});
        }
        if(node->right) {
            q.push({node->right,line+1});
        }

    }
    for(auto i:mp) cout<<i.second<<" ";
    cout<<endl;

}
void verticalview(Node* root) {

    multimap<int,int> mp;
    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty()) {

        auto temp = q.front();
        q.pop();

        Node* node = temp.first;
        int line = temp.second;

        mp.insert({line,node->data});
        
        if(node->left) {
            q.push({node->left,line-1});
        }
        if(node->right) {
            q.push({node->right,line+1});
        }

    }
    int x,y;
    for(auto i:mp) {
        x = i.first;
        if(x!=y){cout<<endl;}
        cout<<i.second<<" ";
        y = i.first;

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

    // leftview(root);
    // topview(root);
    // downview(root);
    verticalview(root);

}