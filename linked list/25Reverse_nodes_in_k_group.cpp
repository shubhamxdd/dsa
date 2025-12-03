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
    Node *head = new Node(arr[0]);
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

Node *findKthNode(Node *head, int k){
    k--;
    Node *temp = head;
    while(temp && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

Node *reverseLL(Node *head){
    Node *temp = head;
    Node *prev=nullptr;
    
    while(temp){
        Node *next = temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}

Node *reverseKgroup(Node *head, int k){
    Node *temp = head;
    Node *prev = nullptr;

    while(temp!=nullptr){
        Node *kthNode = findKthNode(temp, k);
        if(kthNode == nullptr){
            if(prev) prev->next = temp;
            break;
        }
        Node *nextNode = kthNode->next;
        kthNode->next=nullptr;
        reverseLL(temp);

        if(temp==head){
            head=kthNode;
        }else {
            prev->next = kthNode;
        }
        prev = temp;
        temp=nextNode;
    }
    return head;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArrtoLL(arr);
    traverseLL(head);
    head=reverseKgroup(head,3);
    traverseLL(head);

    return 0;
}