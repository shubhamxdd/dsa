#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int v){
            val = v;
            left= nullptr;
            right= nullptr;
        }
};


Node* LCA(Node* root, int p,int q){
    if(root == nullptr) return nullptr;

    int currVal = root->val;

    if(currVal > p && currVal > q ){
        // go left
        return LCA(root->left,p,q);
    }
    if(currVal < p && currVal < q){
        return LCA(root->right,p,q);
    }
    return root;
}


int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->left->right->left = new Node(6);
    root->right = new Node(15);
    root->right->right = new Node(17);
    root->right->left = new Node(13);   

    cout << LCA(root,17,13)->val;
    
    return 0;
}