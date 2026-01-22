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


void preorder(Node *node){
    if(node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void preorderStack(Node *root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node *top = st.top();
        st.pop();
        // if let of top exist, push in stack, same with right
        if(top->right!=nullptr) st.push(top->right);
        if(top->left!=nullptr) st.push(top->left);
        cout << top->data << " ";
    }
}

void inorder(Node *node){
    if(node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void inorderStack(Node *root){
    stack<Node*> st;
    Node *curr = root;
    while(true){
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }else{
            if(st.empty()) break;
            curr = st.top();
            st.pop();
            // print
            cout << curr->data << " ";
            curr=curr->right;
        }

    }
}

void postorder(Node *node){
    if(node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void postorderTwoStacks(Node *root){
    stack<Node*> st1;
    stack<Node*> st2;
    if(root==nullptr) return;
    st1.push(root);

    while(!st1.empty()){
        // pop elemt from s1 and put in s2
        root = st1.top();
        st1.pop();
        st2.push(root);
        
        // if not null move to left, right
        if(root->left!=nullptr) st1.push(root->left);
        if(root->right!=nullptr) st1.push(root->right);
    }
    // now pop s2 and print/push elemt
    while(!st2.empty()){
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void preInPostorderSingle(Node* root){
    if(root == nullptr) return;
    stack<pair<Node*,int>> st;
    st.push({root,1});
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    while(!st.empty()){
        pair<Node*,int> top = st.top();
        st.pop();

        if(top.second == 1){
            // preorder push
            preorder.push_back(top.first->data);
            // second++
            top.second++;
            // pushback in stack
            st.push(top);
            // move left if exist (push in stack)
            if(top.first->left != nullptr){
                st.push({top.first->left,1});
            }
        }else if(top.second == 2){
            // inorder push
            inorder.push_back(top.first->data);
            // second++
            top.second++;
            // push back in stack
            st.push(top);
            // move right if exist (push in stack)
            if(top.first->right != nullptr){
                st.push({top.first->right,1});
            }
        }else {
            // push in post
            postorder.push_back(top.first->data);
        }
    }

    // print all 3 traversals
    cout << "Preorder: ";
    for(int v: preorder){
        cout << v << " ";
    }
    cout << endl;
    cout << "Inorder: ";
    for(int v: inorder){
        cout << v << " ";
    }
    cout << endl;
    cout << "Postorder: ";
    for(int v: postorder){
        cout << v << " ";
    }
}

vector<vector<int>> levelOrderTraversal(Node* root){
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0;i<size;i++){
            Node* tNode = q.front();
            q.pop();
            if(tNode->left != nullptr) q.push(tNode->left);
            if(tNode->right != nullptr) q.push(tNode->right);
            level.push_back(tNode->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    // Creating nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // Simple output to verify tree structure
    // cout << "Root Node: " << root->data << endl;
    // cout << "Left Child of Root: " << root->left->data << endl; 
    // cout << "Right Child of Root: " << root->right->data << endl;
    // cout << "Left Child of Left Node: " << root->left->left->data << endl;
    // cout << "Right Child of Left Node: " << root->left->right->data << endl;

    // cout << "Preorder Traversal: ";
    // preorder(root);
    // cout << endl;
    // cout << "Inorder Traversal: ";
    // inorder(root);
    // cout << endl;
    // cout << "Postorder Traversal: ";
    // postorder(root);
    // cout << endl;

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(6);
    root1->right->left = new Node(7);
    root1->right->right = new Node(8);
    root1->right->right->left = new Node(9);
    root1->right->right->right = new Node(10);

    
    // vector<vector<int>> levelTraversal = levelOrderTraversal(root1);
    // for(vector<int> arr: levelTraversal){
    //     for(int val: arr){
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    // preorderStack(root);
    // inorderStack(root);
    // postorderTwoStacks(root);

    preInPostorderSingle(root);

    return 0;
}