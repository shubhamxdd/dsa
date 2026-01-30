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

vector<vector<int>> verticalTraversal(Node* root){
    vector<vector<int>> ansArr;
    if(root == nullptr) return ansArr;
    map<int,map<int,multiset<int>>> mp;
    queue<pair<Node*, pair<int, int>>> q; // node, int vertical line, int depth/level

    q.push({root,{0,0}});

    while(!q.empty()){
        pair<Node*, pair<int, int>> top = q.front();
        q.pop();

        
        int vertical = top.second.first;
        int level = top.second.second; // depth
     
        // push top in map
        mp[vertical][level].insert(top.first->data);
     
        if(top.first->left != nullptr) q.push({top.first->left,{vertical-1,level+1}});
        if(top.first->right != nullptr) q.push({top.first->right,{vertical+1,level+1}});
    }
    for(auto &p : mp){
        vector<int> col;
        for(auto &q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ansArr.push_back(col);
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

    vector<vector<int>> arr = verticalTraversal(root);

    for(vector<int> vec:arr){
        cout << "{ ";
        for(int val:vec){
            cout << val << " ";
        }
        cout << " }";
    }

    return 0;

}