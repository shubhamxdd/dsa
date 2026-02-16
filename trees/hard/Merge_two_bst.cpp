#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        left = nullptr;
        right = nullptr;
        val = data;
    }
};


void inorderTrav(Node* root, vector<int> &trav){
    if(root == nullptr) return;
    inorderTrav(root->left,trav);
    trav.push_back(root->val);
    inorderTrav(root->right,trav);
}
Node* constructNewTree(vector<int> trav,int start, int end){
    if(start > end) return nullptr;
    int mid = (start+end)/2;
    Node* root = new Node(trav[mid]);

    root->left = constructNewTree(trav,start,mid-1);
    root->right = constructNewTree(trav,mid+1,end);

    return root;
}
Node* mergeTrees(Node* root1, Node* root2) {
    vector<int> t1;
    inorderTrav(root1,t1);
    vector<int> t2;
    inorderTrav(root2,t2);

    t1.insert(t1.end(),t2.begin(),t2.end());
    sort(t1.begin(),t1.end());

    // create new tree with t1 vector

    Node* finalRoot = constructNewTree(t1,0,t1.size()-1);

    return finalRoot;
}

void levelOrderTrav(Node* root){
    vector<vector<int>> ans;
    if(root == nullptr) return;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0;i<size;i++){
            Node* top = q.front();
            q.pop();
            if(top->left!=nullptr) q.push(top->left);
            if(top->right!=nullptr) q.push(top->right);
            level.push_back(top->val);
        }
        ans.push_back(level);
    }

    // traverse ans

    for(vector<int> a:ans){
        cout << "{ ";
        for(int v:a){
            cout << v << " ";
        }
        cout << " }";
    }


}


int main(){
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(5);
    root->right = new Node(2);

    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->left->right = new Node(4);
    root1->right = new Node(3);
    root1->right->right = new Node(7);
    
    Node* mergedRoot = mergeTrees(root,root1);

    levelOrderTrav(mergedRoot);


}