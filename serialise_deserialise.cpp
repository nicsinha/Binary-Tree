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

//Serialise means create any string from a tree such that you can form a tree from that string again

//                1
//             2     3
//                  4   5

// string = 1,2,3,4,5,NULL,NULL,NULL,NULL

string serialise(Node* root) {

    string ans = "";
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();
        if(temp == NULL) {
            ans += '#';
        }
        else {
            ans += temp->data;
            q.push(temp->left);
            q.push(temp->right);
        }
        ans += ',';
    }
    cout<<ans;
    return ans;
}