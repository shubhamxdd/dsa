// convert arr to DLL
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *prev;
        Node *next;
    
    Node(int dataa, Node* prevv, Node *nextt){
        data = dataa;
        prev = prevv;
        next = nextt;
    }
    Node(int dataa){
        data = dataa;
        prev = nullptr;
        next = nullptr;
    }
};

Node *arrayToDLL(vector<int> arr){
    Node *head = new Node(arr[0]);

    Node *prev = head;
    for(int i = 1;i<arr.size();i++){
        // create a new node
        Node *newNode = new Node(arr[i],prev,nullptr);
        prev->next = newNode;
        prev = prev->next;
    }
    return head;
}

void traverseDLL(Node*head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

Node *reverseDLLstack(Node *head){
    Node *temp = head;
    stack<int> st;

    // 2 steps 1. Create stack and push values in it
    // 2. now keep stack.top and assign its value to first elem in DLL and so on

    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp = head;

    
    while(temp!=nullptr){
        // int elem = st.top();
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

Node *reverseDLLlinks(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node *temp = head;

    Node* last = nullptr;

    while(temp!=nullptr){
        last = temp->prev;
        temp->prev = temp->next;
        temp->next=last;

        temp=temp->prev;
    }
    return last->prev;
}

int main(){
    vector<int> arr = {4,2,3,1};
    Node *head = arrayToDLL(arr);
    traverseDLL(head);
    
    // Node *newHead = reverseDLLstack(head);
    // traverseDLL(newHead);

    Node *newHead = reverseDLLlinks(head);
    traverseDLL(newHead);
    


    return 0;
}