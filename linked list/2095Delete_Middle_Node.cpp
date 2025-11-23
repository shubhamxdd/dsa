#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int dataa, Node* nextt){
            data=dataa;
            next=nextt;
        }
        Node(int dataa){
            data=dataa;
            next=nullptr;
        }
};

Node *arrToLL(vector<int> arr){
    Node *head = new Node(arr[0]);

    Node *temp = head;

    for(int i =1;i<arr.size();i++){
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


// reach node before middle
Node* deleteMiddleBrute(Node* head){
    if(head==nullptr || head->next == nullptr) return nullptr;
    Node *temp = head;
    int len = 0;

    while(temp){
        len++;
        temp=temp->next;
    }

    temp=head;
    // cout << len << endl;

    
    int mid = floor(len/2);
    // found middle node, reach it
    Node *midPtr = nullptr;
    while(temp!=nullptr){
        mid--;
        if(mid==0) {
            midPtr = temp->next;
            temp->next=temp->next->next;
            free(midPtr);
            break;
        };
        temp=temp->next;
    }
    // cout << temp->data << endl;

    return head;
}

Node* deleteMiddle(Node *head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    // inc slow by 1 and fast by 2

    while(fast != nullptr && fast->next != nullptr){
        prev = slow;
        slow=slow->next;
        fast=fast->next->next;
    } // if this condition breaks means we got middle element 

    // cout << prev->data << endl;
    // cout << slow->data << endl;

    prev->next = slow->next;

    delete slow;
    return head;
}




int main(){
    vector<int> arr = {4,1,2,3};
    Node *head = arrToLL(arr);
    traverseLL(head);
    // deleteMiddle(head);
    deleteMiddleBrute(head);
    traverseLL(head);
    return 0;
}