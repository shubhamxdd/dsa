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

int maxPathSumRec(Node *root, int &sum){
    if(root == nullptr) return 0;
    // if left/right sum goes below zero, dont consider it, take zero
    int leftSum = max(0,maxPathSumRec(root->left,sum));
    int rightSum = max(0,maxPathSumRec(root->right,sum));
    sum = max(sum, leftSum+rightSum+root->val);
    return root->val + max(leftSum,rightSum);
}
int maxPathSum(Node* root){
    int sum = INT_MIN;
    maxPathSumRec(root, sum);
    return sum;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    cout << maxPathSum(root);
    
    return 0;
}