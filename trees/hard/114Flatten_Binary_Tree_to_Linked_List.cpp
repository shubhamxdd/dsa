#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *left, *right;
    Node(int v){
        val = v;
        left = right = NULL;
    }
};

// brute
// get the preorder traversal of tree, then make right child of each node as next node , left null

void preorderTraversal(Node *root, vector<Node*> &arr){
    if(root == nullptr) return;
    arr.push_back(root);
    preorderTraversal(root->left, arr);
    preorderTraversal(root->right, arr);
}

// vector<Node*> preorder(Node *root){
//     vector<Node*> ans;
//     preorderTraversal(root,ans);
    // for(Node* v:ans) {
    //     cout << v << " ";
    // }
//     return ans;
// }

void flatten(Node*root){
    if(root == nullptr) return;
    vector<Node*> preorderTrav;
    preorderTraversal(root, preorderTrav);

    int n = preorderTrav.size() - 1;

    for(int i = 0;i<n;i++){
        preorderTrav[i]->left = nullptr;
        preorderTrav[i]->right = preorderTrav[i+1];
    }

    // if(!preorderTrav.empty()){
    preorderTrav.back()->left = nullptr;
    preorderTrav.back()->right = nullptr;
    // }
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    // preorder(root);

    return 0;
}