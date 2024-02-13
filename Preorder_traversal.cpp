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
void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


void levelorder(Node* root) {

    queue<Node*> st;

    st.push(root);

    bool check = false;

    while(!st.empty()) {

        int n = st.size();

         
        for(int i=0;i<n;i++) {
            cout<<st.front()->data<<" ";
            Node* node = st.front();
            st.pop();

            if(node->left) {st.push(node->left);}
            if(node->right) {st.push(node->right);}  
        }
        cout<<endl;
    }

}

vector<int> PreOrder_iteration(Node* root) {

    vector<int> res;

    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {
     
      Node* node = st.top();

      st.pop();

      res.push_back(node->data);
      
      if(node->right) {st.push(node->right);}
      if(node->left) {st.push(node->left);}
    }

    return res;

}
vector<int> InOrder_iteration(Node* root) {

    vector<int> res;
    Node* node = root;
    stack<Node*> st;
    
    while(true) {
     
      if(node!=NULL) {

        st.push(node);
        node = node->left;
      }
      else {

        if(st.empty()){break;}

        node = st.top();
        st.pop();
        res.push_back(node->data);
        //cout<<node->data<<" ";
        node = node->right;
      }

    }

    return res;

}



int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // levelorder(root);

    //vector<int> v = PreOrder_iteration(root);

    vector<int> v = InOrder_iteration(root);

    for(auto i:v) {cout<<i<<" ";}
}
