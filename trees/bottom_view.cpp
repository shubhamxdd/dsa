#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

vector<int> bottomView(Node* root){
    vector<int> ansArr;
    if(root == nullptr) return ansArr;
    queue<pair<Node*,int>> q; // stores node* and line
    map<int,int> mp;

    q.push({root,0});

    while(!q.empty()){
        pair<Node*,int> top = q.front();
        q.pop();

        Node *node = top.first;
        int line = top.second;

        // in bottom view we update values directly
        // without checking if it does not exist or not
        // so over write it
        mp[line]=node->data;

        // if left exist push left in q
        if(node->left !=nullptr) q.push({node->left,line-1});
        // same with right
        if(node->right !=nullptr) q.push({node->right,line+1});
    }

    for(auto v:mp){
        ansArr.push_back(v.second);
    }
    
    return ansArr;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(3);
    root1->left->left->right = new Node(4);
    root1->left->left->right->left = new Node(5);
    root1->left->left->right->right = new Node(6);

    root1->right = new Node(7);
    root1->right->right = new Node(8);
    root1->right->right->left = new Node(9);
    root1->right->right->left->left = new Node(10);
    root1->right->right->left->right = new Node(11);

    vector<int> arr = bottomView(root);

    for(int v:arr){
        cout << v << " ";
    }

    return 0;

}