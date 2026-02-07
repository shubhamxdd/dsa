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

void changeTree(Node* root){
    if(root == nullptr) return;
    int sum = 0;
    if(root->left) sum+=root->left->val;
    if(root->right) sum+=root->right->val;

    if(sum>= root->val) root->val = sum;
    else{
        if(root->left) root->left->val = root->val;
        else if(root->right) root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total+=root->left->val;
    if(root->right) total+=root->right->val;
    if(root->left || root->right) root->val = total;
    
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    changeTree(root);

    return 0;
}