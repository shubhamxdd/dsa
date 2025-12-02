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

Node *deleteOccurences(Node* head, int key){
    if(head==nullptr) return nullptr;

    Node *temp = head;
    while(temp){
        if(temp->data == key){
            if(temp==head){
                // delete head
                head=head->next;
            }
            Node *nextNode = temp->next;
            Node *prevNode = temp->back;

            if(nextNode){
                nextNode->back = prevNode;
            }
            if(prevNode){
                prevNode->next=nextNode;
            }
            delete temp;

            temp=temp->next;
        }else {
            temp=temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {2,3,4,1,3,5,3};
    Node *head = arrayToDLL(arr);
    traverseDLL(head);
    int key = 3;
    head = deleteOccurences(head,key);
    traverseDLL(head);
    return 0;
}