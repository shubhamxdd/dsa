#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

int isBalanced(Node* root){
    if(root == nullptr) return 0;
    int left = isBalanced(root->left);
    if(left == -1) return -1;
    int right = isBalanced(root->right);
    if(right == -1) return -1;
    if(abs((left-right)>1)) return -1;
    return 1 + max(left, right);
}

bool checkBalanced(Node *root){
    return isBalanced(root) != -1;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->right = new Node(6);
    cout << checkBalanced(root) <<  endl;

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    cout << checkBalanced(root1) << endl;


    return 0;
}