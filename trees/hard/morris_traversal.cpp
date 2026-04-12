#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *left, *right;
    Node(int v){
        val = v;
        left = right = NULL;
    }
};

vector<int> morrisInorder(Node* root){
    vector<int> ans;

    Node *curr = root;

    while(curr!=nullptr){
        if(curr->left == nullptr){
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else{
            // find inorder predecessor of curr
            Node *prev = curr->left;
            while(prev->right && prev->right != curr){
                prev=prev->right;
            }

            if(prev->right == nullptr){
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=nullptr;
                ans.push_back(curr->val);
                curr=curr->right;
            }

        }
    }
    return ans;
}

int main(){
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->right->left = new Node(6);
    // root->right->left = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->left = new Node(9);
    // root->right->right->right = new Node(10);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> morisTrav = morrisInorder(root);
    for(int v:morisTrav) cout << v << " ";



    return 0;
}