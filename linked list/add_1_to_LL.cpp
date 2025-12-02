#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data1,Node *next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArrtoLL(vector<int> &arr){
    Node *head = new Node(arr[0]); // first node 
    Node *mover = head; 

    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]); 
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverseLL(Node* head){
    Node *temp = head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverseLL(Node *head){
    Node *temp = head;
    Node *prev = nullptr;
    
    while(temp!=nullptr){
        Node *front = temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node *addOneBrute(Node *head){
    head=reverseLL(head);
    Node *temp = head;
    int carry = 1;
    while(temp!=nullptr){
        temp->data=temp->data+carry;
        if(temp->data<10){
            carry=0;
            break;
        }else {
            temp->data = 0;
            carry=1;
        }
        temp=temp->next;
    }

    if(carry==1){
        Node *newNode = new Node(carry);
        head = reverseLL(head);
        newNode->next=head;
        return newNode;
    }else {
        head = reverseLL(head);
        return head;
    }
    return nullptr;

}


int main(){
    // vector<int> arr = {9,9,9};
    vector<int> arr = {1,4,9};
    Node *head = convertArrtoLL(arr);
    traverseLL(head);
    Node *ans = addOneBrute(head);
    traverseLL(ans);
    return 0;
}