#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
        Node(int val, Node* n) {
            data = val;
            next = n;
        }
        Node(int val) {
            data = val;
            next = NULL;
        }
};

Node *arrayToLL(vector<int> arr){ 
    Node *head = new Node(arr[0]);
    Node *temp = head;

    for(int i = 1;i<arr.size();i++){
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp=newNode;
    }
    return head;
}

void traverseLL(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* sortListBrute(Node *head){
    // put elements in arr
    vector<int> arr;
    Node *temp = head;
    
    while(temp){
        arr.push_back(temp->data);
        temp=temp->next;
    }

    // sort array
    sort(arr.begin(),arr.end());

    // temp to head
    temp=head;


    // replace
    int i = 0;
    while(temp!=nullptr){
        temp->data=arr[i];
        temp=temp->next;
        i++;
    }
    return head;
}

Node *findMiddle(Node* head){
    //tortoise hare

    Node *slow = head;
    Node *fast = head->next;

    while(fast!=nullptr && fast->next !=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node *mergeList(Node *list1, Node*list2){
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data < list2->data){
            temp->next = list1;
            temp=list1;
            list1=list1->next;
        }else {
            temp->next = list2;
            temp=list2;
            list2=list2->next;
        }
    }
    if(list1){
        temp->next=list1;
    }else {
        temp->next=list2;
    }
    return dummyNode->next;
}

Node* sortListOptimal(Node *head){
    if(head==nullptr || head->next==nullptr) return head;

    // break from middle using tortoise hare
    Node *middle = findMiddle(head);
    
    Node *leftHead = head;
    Node *rightHead = middle->next;

    middle->next=nullptr;
    leftHead = sortListOptimal(leftHead);
    rightHead = sortListOptimal(rightHead);

    return mergeList(leftHead,rightHead);
}

int main(){
    vector<int> arr = {4,2,1,3};
    Node *head = arrayToLL(arr);
    traverseLL(head);
    Node *sortedHead = sortListOptimal(head);
    traverseLL(sortedHead);
    return 0;
}