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

bool isLeaf(Node *root){
    return (root->left == nullptr) && (root->right == nullptr);
}

void addLeftNodes(Node* root, vector<int> &ans){
    Node *curr = root->left;

    while(curr!=nullptr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void addLeafNodes(Node* root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeafNodes(root->left,ans);
    if(root->right) addLeafNodes(root->right,ans);
}

void addRightNodes(Node *root, vector<int> &ans){
    Node *curr = root->right;
    // reverse right traversal
    vector<int> trav;
    while(curr!=nullptr){
        if(!isLeaf(curr)) trav.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    // reverse(trav.begin(),trav.end());
    for(int i = trav.size()-1;i>=0;i--){
        ans.push_back(trav[i]);
    }
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    // travel left side
    // if reach leaf, dont add and break
    addLeftNodes(root,ans);
    // preorder traversal for leaf nodes
    addLeafNodes(root,ans);
    // right in reverse
    addRightNodes(root,ans);

    return ans;
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

    vector<int> res = boundaryTraversal(root1);

    for(int v:res){
        cout << v << " ";
    }

}