#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *back;
        Node *next;

    Node(int data1,Node*back1, Node*next1){
        back=back1;
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        back=nullptr;
        next=nullptr;
    }

};

Node* arrayToDLL(vector<int> &arr){
    // create a new node with first element (head)
    Node* head = new Node(arr[0]); // with only data

    Node* prev = head;

    for(int i = 1;i<arr.size();i++){
        // create temp node
        Node* temp = new Node(arr[i],prev,nullptr);
        prev->next = temp;
        prev=prev->next;
    }
    return head;
}

void traverseDLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

Node *removeDuplicates(Node* head){
    Node *temp = head;
    while(temp!=nullptr && temp->next!=nullptr){
        Node *nextNode = temp->next;
        while(nextNode!=nullptr && nextNode->data == temp->data){
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        temp->next = nextNode;
        if(nextNode!=nullptr){
            nextNode->back = temp;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,1,2,3,3,4,4,4,5,6,6};
    Node* head = arrayToDLL(arr);
    traverseDLL(head);
    head = removeDuplicates(head);
    traverseDLL(head);
    return 0;
}