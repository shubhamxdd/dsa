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


bool solve(Node* root, int tgt, vector<Node*>& ans) {
    if (root == nullptr)
        return false;
    ans.push_back(root);
    // chech is latest pushed value is tgt
    if (root->val == tgt)
        return true;

    if (solve(root->left, tgt, ans) || solve(root->right, tgt, ans)) {
        return true;
    }
    ans.pop_back();
    return false;
}

vector<Node*> rootToNodePath(Node* root, int num) {
    vector<Node*> ansArr;
    solve(root, num, ansArr);
    return ansArr;
}

Node* lowestCommonAncestorBrute(Node* root, Node* p, Node* q) {
    vector<Node*> pathP = rootToNodePath(root, p->val);
    vector<Node*> pathQ = rootToNodePath(root, q->val);

    // find common bw both vectors
    for(int i = pathP.size()-1;i>=0;i--){
        for(int j = pathQ.size()-1;j>=0;j--){
            if(pathP[i]->val == pathQ[j]->val){
                return pathP[i];
            }
        }
    }
    return root;
}




Node *lowestCommonAncestorOptimal(Node* root, Node* p, Node* q){
    if(root == nullptr || root == p || root == q) return root;

    // call for left
    Node *left = lowestCommonAncestorOptimal(root->left,p,q);
    // call for right
    Node *right = lowestCommonAncestorOptimal(root->right,p,q);

    if(left != nullptr && right != nullptr) return root;
    else if(left != nullptr && right == nullptr) return left;
    else if(left == nullptr && right != nullptr) return right;
    else return nullptr;

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
    
    // Node* ans = lowestCommonAncestorBrute(root, root->left->right, root->right);
    Node* ans = lowestCommonAncestorOptimal(root, root->left->right, root->right);

    cout << ans->val << endl;


    return 0;
}