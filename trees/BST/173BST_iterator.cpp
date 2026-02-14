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


// brute
class BSTIterator {
public:
    vector<Node*> inorderTravVector;
    int currPtr;

    void inorderTrav(Node* root, vector<Node*>& ansVec) {
        if (root == nullptr)
            return;
        inorderTrav(root->left, ansVec);
        ansVec.push_back(root);
        inorderTrav(root->right, ansVec);
    }

    BSTIterator(Node* root) {
        inorderTrav(root, inorderTravVector);
        currPtr = 0;
    }

    int next() {
        if (inorderTravVector[currPtr]) {
            return inorderTravVector[currPtr++]->val;
        }
        return false;
    }

    bool hasNext() {
        int size = inorderTravVector.size() - 1;
        if (currPtr == size + 1)
            return false;
        if (inorderTravVector[currPtr])
            return true;
        return false;
    }
};

int main(){
    Node* root = new Node(10);
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->left->right->left = new Node(6);
    root->right = new Node(15);
    root->right->right = new Node(17);
    root->right->left = new Node(13);   


    return 0;
}