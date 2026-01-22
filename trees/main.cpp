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


void preorder(Node *node){
    if(node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node *node){
    if(node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void postorder(Node *node){
    if(node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main(){
    // Creating nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // Simple output to verify tree structure
    // cout << "Root Node: " << root->data << endl;
    // cout << "Left Child of Root: " << root->left->data << endl; 
    // cout << "Right Child of Root: " << root->right->data << endl;
    // cout << "Left Child of Left Node: " << root->left->left->data << endl;
    // cout << "Right Child of Left Node: " << root->left->right->data << endl;



    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;



    return 0;
}