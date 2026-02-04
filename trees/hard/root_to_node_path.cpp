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

bool solve(Node* root, int tgt, vector<int> &ans){
    if(root == nullptr) return false;
    ans.push_back(root->val);
    // chech is latest pushed value is tgt
    if(root->val == tgt) return true;

    if(solve(root->left,tgt,ans) || solve(root->right,tgt,ans)){
        return true;
    }
    ans.pop_back();
    return false;

}

vector<int> rootToNodePath(Node *root, int num){
    vector<int> ansArr;
    solve(root,num, ansArr);
    return ansArr;
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
    
    vector<int> ans = rootToNodePath(root, 5);

    for(int v:ans){
        cout << v << " ";
    }

    

    return 0;
}