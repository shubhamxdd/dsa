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

// brute

void inorderTrav(Node* root, vector<int> &ans){
    if(root == nullptr) return;
    inorderTrav(root->left,ans);
    ans.push_back(root->data);
    inorderTrav(root->right,ans);
}
bool findTargetBrute(Node* root, int k) {
    vector<int> trav;
    inorderTrav(root, trav);

    for(int i = 0;i<trav.size();i++){
        for(int j = i+1;j<trav.size();j++){
            if(trav[i] + trav[j] == k) return true;
        }
    }
    return false;
}

bool findTargetBetter(Node* root, int k) {
    vector<int> trav;
    inorderTrav(root, trav);

    int l = 0;
    int r = trav.size()-1;

    while(r>l){
        if(trav[l]+trav[r] == k) return true;
        
        if(trav[l] + trav[r] > k) r--;
        else if(trav[l]+trav[r] < k) l++;
    }
    return false;
}


class BSTIterator{
    public:
        stack<Node*> st;
        bool reverse = true; // if true=> before(right root left) if false =>(left root right)
        BSTIterator(Node* root, bool isRev){
            reverse = isRev;
            pushAll(root);
        }
        
        void pushAll(Node* root){
            while(root){
                st.push(root);
                if(reverse == true) root=root->right;
                else root=root->left;
            }
        }

        int next(){
            Node* top = st.top();
            st.pop();

            if(reverse == true) pushAll(top->left);
            else pushAll(top->right);
            return top->data;
        }
        bool hasNext(){
            return !st.empty();
        }
};

bool findTargetOptimal(Node* root,int k){
    if(root == nullptr) return false;
    BSTIterator l(root,false);
    BSTIterator r(root,true);

    int i = l.next();
    int j = r.next();

    while(j>i){
        if(i + j == k) return true;

        if(i + j > k) j = r.next();
        else i = l.next();
    }
    return false;

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


    cout << findTargetOptimal(root,11);

    return 0;
}