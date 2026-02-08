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

void getParentNodes(Node* root, unordered_map<Node*,Node*> &track_parents){
    if(!root) return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr->left){
            track_parents[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            track_parents[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

Node* findTarget(int target, Node* root){
    if(!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->val == target) return curr;
        // call left and right recursively
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return nullptr;
}

int minTimeToBurnTree(Node* root, int target){
    Node* targetNode = findTarget(target, root);
    if(!root || !targetNode) return 0;
    unordered_map<Node*,Node*> track_parents;
    getParentNodes(root,track_parents);

    unordered_map<Node*,bool> visited;

    queue<Node*> q;
    q.push(targetNode);
    visited[targetNode] = true;

    int curr_time = 0;

    while(!q.empty()){
        int size = q.size();
        bool burned = false;
        // curr_time++;
        for(int i = 0;i<size;i++){
            Node* curr = q.front();
            q.pop();

            // traverse it radially, top, left and right
            if(curr->left && !visited[curr->left]){
                // push in q and mark as visited
                q.push(curr->left);
                visited[curr->left] = true;
                burned = true;
            }
            if(curr->right && !visited[curr->right]){
                // push in q and mark as visited
                q.push(curr->right);
                visited[curr->right] = true;
                burned = true;
            }
            // parent node
            if(track_parents[curr] && !visited[track_parents[curr]]){
                // push in q and mark as visited
                q.push(track_parents[curr]);
                visited[track_parents[curr]] = true;
                burned = true;
            }
        }
        if(burned == true) curr_time++;
    }
    return curr_time;
}

/*
int minTimeToBurnTree(Node* root, Node* target){
    if(!root || !target) return 0;
    unordered_map<Node*,Node*> track_parents;
    getParentNodes(root,track_parents);

    unordered_map<Node*,bool> visited;

    queue<Node*> q;
    q.push(target);
    visited[target] = true;

    int curr_time = 0;

    while(!q.empty()){
        int size = q.size();
        bool burned = false;
        // curr_time++;
        for(int i = 0;i<size;i++){
            Node* curr = q.front();
            q.pop();

            // traverse it radially, top, left and right
            if(curr->left && !visited[curr->left]){
                // push in q and mark as visited
                q.push(curr->left);
                visited[curr->left] = true;
                burned = true;
            }
            if(curr->right && !visited[curr->right]){
                // push in q and mark as visited
                q.push(curr->right);
                visited[curr->right] = true;
                burned = true;
            }
            // parent node
            if(track_parents[curr] && !visited[track_parents[curr]]){
                // push in q and mark as visited
                q.push(track_parents[curr]);
                visited[track_parents[curr]] = true;
                burned = true;
            }
            if(burned == true) curr_time++;
        }

    }

    return curr_time;
}
*/
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    // cout << minTimeToBurnTree(root,root->left);
    cout << minTimeToBurnTree(root,4);


    return 0;
}