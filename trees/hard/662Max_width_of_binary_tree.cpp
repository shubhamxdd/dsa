#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *left, *right;
    Node(int v){
        val = v;
        left = right = NULL;
    }
};

int maxWidth(Node* root){
    if(root == nullptr) return 0;
    int ans = 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int first,last;
        for(int i = 0;i<size;i++){
            int curr_id = q.front().second - min;
            Node* top = q.front().first;
            q.pop();
            if(i == 0) first = curr_id;
            if(i == size-1) last = curr_id;
            if(top->left != nullptr) q.push({top->left,(curr_id*2)+1});
            if(top->right != nullptr) q.push({top->right,(curr_id*2)+2});
        }

        ans = max(ans,last-first+1);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    int ans = maxWidth(root);

    cout << ans;

    return 0;
}