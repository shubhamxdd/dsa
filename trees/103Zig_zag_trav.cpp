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

vector<vector<int>> zigZagTrav(Node* root){
    vector<vector<int>> result;
    queue<Node *> q;
    q.push(root);

    // if true means push tree level traversal in right to left, false mean left to right
    bool flag = false;
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0;i<size;i++){
            Node *top = q.front();
            q.pop();
            if(top->left !=nullptr) q.push(top->left);
            if(top->right!=nullptr) q.push(top->right);
            level.push_back(top->data);
        }
        if(flag == true){
            reverse(level.begin(),level.end());
        }
        result.push_back(level);
        flag = !flag;
    }
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> res =  zigZagTrav(root);

    for(vector<int> v:res){
        cout << "{ ";
        for(int val:v){
            cout << val << " ";
        }
        cout << " } " << endl;
    }
}