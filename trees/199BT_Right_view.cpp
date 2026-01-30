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

void rightViewRec(Node* root, vector<int> &ans,int level){
    if(root == nullptr) return;
    if(level == ans.size()){
        // means seeing this element for this first time, so push it
        ans.push_back(root->data);
    }
    // we use reverse preorder here
    // right left root
    rightViewRec(root->right,ans,level+1);
    rightViewRec(root->left,ans,level+1);
}
vector<int> rightViewBT(Node *root){
    vector<int> arr;
    if(root == nullptr) return arr;
    rightViewRec(root,arr,0);

    return arr;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(3);
    root1->left->left->right = new Node(4);
    root1->left->left->right->left = new Node(5);
    root1->left->left->right->right = new Node(6);

    root1->right = new Node(7);
    root1->right->right = new Node(8);
    root1->right->right->left = new Node(9);
    root1->right->right->left->left = new Node(10);
    root1->right->right->left->right = new Node(11);

    vector<int> arr = rightViewBT(root);


    for(int val:arr){
        cout << val << " ";
    }

    return 0;

}