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

bool helper(Node* root, long min, long max){
    if(root == nullptr) return true;

    if(root->val >=max || root->val<=min) return false;

    return helper(root->left,min,root->val) && helper(root->right,root->val,max);

}


bool validateBST(Node* root){
    return helper(root, LONG_MIN, LONG_MAX);    
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

    cout << validateBST(root);

    
    return 0;
}