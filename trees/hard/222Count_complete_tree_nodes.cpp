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

void inorderTrav(Node* root, int &cnt){
    if(root == nullptr) return;
    cnt++;
    if(root->left) inorderTrav(root->left,cnt);
    if(root->right) inorderTrav(root->right,cnt);
}

int countNodes(Node* root){
    int cnt = 0;
    inorderTrav(root,cnt);
    return cnt;
}

int findLeftHeight(Node *root){
    int h = 0;
    while(root){
        h++;
        root=root->left;
    }
    return h;
}
int findRightHeight(Node *root){
    int h = 0;
    while(root){
        h++;
        root=root->right;
    }
    return h;
}


int optimal(Node* root){
    if(root == nullptr) return 0;
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if(lh == rh) return pow(2,lh) - 1;
    return 1 + optimal(root->left) + optimal(root->right);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    // brute
    // cout << countNodes(root);

    cout << optimal(root);


    return 0;
}