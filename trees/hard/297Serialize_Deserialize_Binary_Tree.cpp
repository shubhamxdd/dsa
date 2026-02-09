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

string serialize(Node* root){
    if(root == nullptr) return "";
    string s = "";
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* top = q.front();
        q.pop();

        if(top == nullptr) s.append("#,");
        else s.append(to_string(top->val)+',');
        if(top != nullptr){
            q.push(top->left);
            q.push(top->right);
        }
    }
    return s;
}

Node *deserialize(string data){
    if(data.size() == 0) return nullptr;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node *root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *top = q.front();
        q.pop();

        getline(s,str,',');
        if(str == "#") top->left = nullptr;
        else {
            Node *leftNode = new Node(stoi(str));
            top->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str == "#") top->right = nullptr;
        else {
            Node *rightNode = new Node(stoi(str));
            top->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
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


    string s = serialize(root);

    Node *newRoot = deserialize(s);

    string s2 = serialize(newRoot);
    cout << "Original serialization:   " << s << endl;
    cout << "After deserialization:    " << s2 << endl;

    if(s == s2) cout << "Success: Tree is correctly serialized and deserialized!" << endl;
    else cout << "Failure: Trees do not match!" << endl;

    return 0;
}