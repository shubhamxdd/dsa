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

int lenOfLL(Node *head){
    Node *temp = head;
    int len = 0;

    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}

Node *removeNthFromBack(Node *head, int n){
    Node *temp = head;
    Node *prev=nullptr;
    int lenLL = lenOfLL(head);

    if(lenLL == n){
        // deleteHead;
        Node *newHead = head->next;
        free(head);
        return newHead;
    }


    int nodeFromFront = lenLL-n;
    temp=head;

    while(temp!=nullptr){
        nodeFromFront--;
        if(nodeFromFront==0) break;
        temp=temp->next;
    }

    Node *delNode = temp->next;
    temp->next=temp->next->next;
    delete delNode;
    return head;
}

Node* removeNthFromBackOptimal(Node *head, int n){
    Node *slow = head;
    Node *fast = head;

    // move fast pointer n places forward

    for(int i=0;i<=n;i++){
        fast=fast->next;
    }

    // edge case
    if(fast==nullptr) return head->next;

    // move both simultaneously
    while(fast){
        fast=fast->next;
        slow=slow->next;
    }
    Node *delNode = slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
    
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = arrayToLL(arr);
    // cout << lenOfLL(head)<<endl;
    traverseLL(head);

    // removeNthFromBack(head,2);
    removeNthFromBackOptimal(head,2);
    traverseLL(head);
    return 0;
}