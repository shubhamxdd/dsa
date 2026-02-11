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

Node* findLastRight(Node* root){
    // if(root == nullptr) return root;
    // return findRightMostChild(root->right);
    while(root->right != nullptr) root=root->right;
    return root;
}

Node* helper(Node* root){
    if(root->left == nullptr) return root->right;
    else if(root->right == nullptr) return root->left;

    Node* rightChild = root->right;
    Node* lastRightChild = findLastRight(root->left);

    lastRightChild->right = rightChild;
    
    return root->left;
}

Node* deleteFromBST(Node* root, int val) {
    if(root == nullptr) return nullptr;
    if(root->val == val) return helper(root); // delete head

    Node* dummy = root;
    while(root){
        if(root->val > val){
            if(root->left!=nullptr && root->left->val == val){
                // call helper
                root->left = helper(root->left);
            }else {
                // move left
                root = root->left;
            }
        }else {
            if(root->right != nullptr && root->right->val == val){
                // call helper
                root->right = helper(root->right);
            }else{
                // move right
                root=root->right;
            }
        }
    }
    return dummy;
}


vector<vector<int>> levelOrderTrav(Node* root){
    vector<vector<int>> ans;
    if(root == nullptr) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i = 0;i<size;i++){
            Node* top = q.front();
            q.pop();

            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            level.push_back(top->val);
        }
        ans.push_back(level);
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
    
    vector<vector<int>> ans = levelOrderTrav(root);

    for(vector<int> vec:ans){
        for(int v:vec){
            cout << v << " ";
        }
        cout << endl;
    }
    
    Node *newRoot = deleteFromBST(root,8);
    cout << endl;

    vector<vector<int>> ans1 = levelOrderTrav(newRoot);

    for(vector<int> vec:ans1){
        for(int v:vec){
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}