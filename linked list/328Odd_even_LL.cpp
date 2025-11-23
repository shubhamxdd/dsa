#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
    
    Node(int dataa, Node *nextt){
        data = dataa;
        next=nextt;
    }
    Node(int dataa){
        data = dataa;
        next=nullptr;
    }
};

Node *arrayToLL(vector<int> arr){
    Node *head = new Node(arr[0]);

    Node *temp = head;
    for(int i = 1;i<arr.size();i++){
        Node *newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
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


Node *oddEvenLL(Node *head){
    if(head==nullptr || head->next == nullptr) return head;
    Node *temp = head;
    vector<int> arr;

    // odd indexes

    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);

    
    // even index 
    temp=head->next;
    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    
    temp=head;
    int i = 0;
    while(temp){
        temp->data=arr[i++];
        temp=temp->next;
    }
    traverseLL(head);

    return head;


}

Node *oddEvenLLOptimal(Node *head){
    if(head==nullptr && head->next!=nullptr) return head;
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;

    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
    }

    odd->next=evenHead;
    return head;

}


int main(){
    // vector<int> arr = {4,2,1,3};
    vector<int> arr = {1,3,4,2,5,6};
    Node *head = arrayToLL(arr);
    traverseLL(head);
    Node *newHead = oddEvenLLOptimal(head);
    traverseLL(newHead);

    return 0;
}