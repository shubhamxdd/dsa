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

void inorder(Node* root, vector<int> &trav){
    if(root == nullptr) return;
    inorder(root->left,trav);  
    trav.push_back(root->val);
    inorder(root->right,trav); 
}

void fix(Node *root, vector<int> &sortedVals,int &i){
    if(root == nullptr) return;
    fix(root->left,sortedVals,i);
    root->val = sortedVals[i++];
    fix(root->right,sortedVals,i);
}

void recoverTreeBrute(Node* root){
        vector<int> inorderTrav;
        inorder(root,inorderTrav);
        sort(inorderTrav.begin(),inorderTrav.end());

        int i = 0;
        // now fix it
        fix(root,inorderTrav,i);

}

Node* prevNode = nullptr;
Node* first = nullptr;
Node* second = nullptr;

void recoverTreeOptimalRec(Node* root){
    if(root == nullptr) return;
    
    recoverTreeOptimalRec(root->left);

    if(prevNode!=nullptr && prevNode->val > root->val){
        if(first == nullptr){
            first = prevNode;
        }
        second = root;
    }
    prevNode = root;

    recoverTreeOptimalRec(root->right);
}
void recoverTreeOptimal(Node* root){
    recoverTreeOptimalRec(root);

    swap(first->val,second->val);
}

// level order trav

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
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);


    levelOrderTrav(root);
    cout << endl;
    recoverTreeBrute(root);
    cout << endl;
    levelOrderTrav(root);


    return 0;
}