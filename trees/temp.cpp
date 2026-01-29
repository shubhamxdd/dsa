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

void allTraversals(Node *root){
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;
    stack<pair<Node*,int>> st;
    st.push({root,1});

    while(!st.empty()){
        pair<Node*,int> top = st.top();
        st.pop();

        if(top.second == 1){
            preOrder.push_back(top.first->data);
            top.second++;
            st.push(top);
            // if left exist push that
            if(top.first->left != nullptr) st.push({top.first->left,1});
        }else if(top.second==2){
            inOrder.push_back(top.first->data);
            top.second++;
            st.push(top);
            // if right exist go there
            if(top.first->right != nullptr) st.push({top.first->right,1});
        }else{
            // top.second == 3
            postOrder.push_back(top.first->data);
        }
    }
    // print all 3 arrays
    cout << "Preorder: ";
    for(int v:preOrder) cout << v << " ";
    cout << endl;
    cout << "Inorder: ";
    for(int v:inOrder) cout << v << " ";
    cout << endl;
    cout << "Postorder: ";
    for(int v:postOrder) cout << v << " ";
    cout << endl;
}

void bfs(Node *root){
    vector<vector<int>> bfsAns;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> trav;
        for(int i = 0;i<size;i++){
            Node* front = q.front();
            q.pop();

            if(front->left!=nullptr) q.push(front->left);
            if(front->right!=nullptr) q.push(front->right);
            trav.push_back(front->data);
        }
        bfsAns.push_back(trav);     
    }
    // print bfsAns
    for(vector<int> bfs:bfsAns){
        cout << "{ ";
        for(int v:bfs){
            cout << v << " ";
        }
        cout << "}";
        cout << endl;
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    allTraversals(root);
    bfs(root);
    return 0;
}