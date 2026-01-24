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

int findHeight(Node *root){
    if(root == nullptr) return 0;
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    return 1 + max(left,right);
}

void diameterBruteRec(Node *root, int &maxV){
    if(root == nullptr) return;
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    // cout << "Left: " << left << endl;
    // cout << "Right: " << right << endl;
    maxV = max(maxV,left+right);
    // cout << "MaxV: " << maxV << endl;
    
    diameterBruteRec(root->left,maxV);
    diameterBruteRec(root->right,maxV);
}

int diameterBrute(Node *root){
    int maxV = 0;
    diameterBruteRec(root,maxV);
    return maxV;
}


int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    
    cout << diameterBrute(root);

    return 0;
}