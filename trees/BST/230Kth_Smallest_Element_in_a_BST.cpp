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

void inorderTrav(Node* root, vector<int> &trav){
    if(root == nullptr) return;
    inorderTrav(root->left,trav);
    trav.push_back(root->val);
    inorderTrav(root->right,trav);
}

int kthSmallestBrute(Node* root, int k){
    if(root == nullptr) return -1;
    vector<int> trav;
    inorderTrav(root,trav);
    sort(trav.begin(),trav.end());
    return trav[k-1];
}

int kthSmallestBetter(Node* root, int k){
    if(root == nullptr) return -1;
    vector<int> trav;
    inorderTrav(root,trav);
    // sort(trav.begin(),trav.end()); // inorder traversal of bst are already sorted so no need to sort them
    return trav[k-1];
}

int inorder(Node* root, int &count, int k){
    if(root == nullptr) return -1;
    int ans = root->val;

    int left = inorder(root->left,count,k);
    if(left!=-1) return left;
    count++;
    if(count == k){
        return ans;
    }
    return inorder(root->right,count,k);
}

int kthSmallestOptimal(Node* root, int k){
    int cnt = 0;
    return inorder(root, cnt, k);
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

    // cout << kthSmallestBrute(root,2);
    // cout << kthSmallestBetter(root,2);
    cout << kthSmallestOptimal(root,2);
    
    return 0;
}