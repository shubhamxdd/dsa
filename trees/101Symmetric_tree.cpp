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

bool isSymmetric(Node *p, Node *q){
    if(p == nullptr || q == nullptr) return (p==q);
    return (p->val == q->val) && isSymmetric(p->left,q->right) && isSymmetric(p->right,q->left);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right = new Node(3);
    
    
    cout << isSymmetric(root,root1);

    return 0;
}