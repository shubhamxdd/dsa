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

Node* insertIntoBST(Node* root, int val) {
    if(root == nullptr) return new Node(val);

    Node* curr = root;

    while(curr){
        if(curr->val >= val){
            // go left, curr = 5 and to insert it 4,3,2...
            // if left is not null, go there, if its null, insert node with val
            if(curr->left != nullptr) curr = curr->left;
            else {curr->left = new Node(val); break;}
        }else{
            // go right
            // if right is not null, go there, if its null, insert a node with val
            if(curr->right!=nullptr) curr=curr->right;
            else {curr->right = new Node(val);break;}
        }
    }
    return root;
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

    Node *newRoot = insertIntoBST(root,91);

    vector<vector<int>> ans = levelOrderTrav(newRoot);

    for(vector<int> vec:ans){
        for(int v:vec){
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}