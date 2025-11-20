#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
    
    Node(int dataa, Node* nextt){
        data = dataa;
        next = nextt;
    }
    Node(int dataa){
        data = dataa;
        next = nullptr;
    }
};

Node *arrayToLL(vector<int> arr){
    Node *head = new Node(arr[0]);

    Node *temp = head;

    for(int i = 1;i<arr.size();i++){
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp=temp->next;
    }
    return head;
}

void traverseLL(Node *head){
    Node *temp = head;

    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

Node *reverseLLStack(Node *head){
    stack<int> st;

    Node *temp = head;

    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }

    temp = head;

    while(temp!=nullptr){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
    return head;   
}

Node *reverseLLOptimal(Node *head){
    Node *temp = head;
    Node *prev = nullptr;

    while(temp!=nullptr){
        Node *front = temp->next;
        temp->next = prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

int main(){
    vector<int> arr = {1,3,2,5};
    Node *head = arrayToLL(arr);
    traverseLL(head);
    // Node *newHead = reverseLLStack(head);
    // traverseLL(newHead);
    Node *newHead = reverseLLOptimal(head);
    traverseLL(newHead);
    // traverseLL(head);

    return 0;
}