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


int floor(Node* root, int val){
    if(root == nullptr) return -1;
    Node *c = root;
    int ans = -1;
    while(c){
        if(c->val == val){
            ans = c->val;
            return ans;
        }
        
        if(c->val < val){
            // go left
            ans=c->val;
            c=c->right;
        }
        else{
            c=c->left;
        }
    }
    return ans;
}

int ceil(Node* root, int val){
    if(root == nullptr) return -1;
    int ans = -1;

    while(root){
        if(root->val == val){
            ans = root->val;
            return ans;
        }

        if(root->val > val){
            ans=root->val;
            root=root->left;
        }else{
            root = root->right;
        }
    }
    return ans;
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

    cout << floor(root,16) << endl;
    cout << ceil(root,16) << endl;

    return 0;
}