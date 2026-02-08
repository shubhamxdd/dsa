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

void markParents(Node* root,unordered_map<Node*,Node*> &track_parent_node){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left){
            track_parent_node[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            track_parent_node[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(Node* root, Node* target, int k) {
    unordered_map<Node*,Node*> track_parent_node;
    markParents(root,track_parent_node); // level order traversal, BFS, to track parent of each node

    // traverse upwards, leftwards and rightwards
    unordered_map<Node*,bool> visited;

    queue<Node*> q;
    q.push(target);

    visited[target] = true;
    int curr_dist = 0;

    while(!q.empty()){
        int size = q.size();
        if(curr_dist == k) break;
        curr_dist++;

        for(int i = 0;i<size;i++){
            Node* curr = q.front();
            q.pop();

            if(curr->left && !visited[curr->left]){ // left exist and not visited already push in q
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right && !visited[curr->right]){ // right exist and not visited already push in q
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(track_parent_node[curr] && !visited[track_parent_node[curr]]){
                q.push(track_parent_node[curr]);
                visited[track_parent_node[curr]] = true;
            }
        }
    }

    vector<int> res;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        res.push_back(curr->val);
    }
    return res;
}


int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    vector<int> ans = distanceK(root,root->left,1);
    for(int v:ans) cout << v << " ";


    return 0;
}