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

Node* deleteHead(Node *head){
    if(head==nullptr) return nullptr;
    if(head->next==nullptr) return nullptr;
    Node *temp = head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr || head->next == nullptr) return nullptr;
    Node *tail = head;

    while(tail->next!=nullptr){
        tail=tail->next;
    } // tail will be on last element
    Node *secondLast = tail->back;
    tail->back=nullptr;
    secondLast->next=nullptr;
    free(tail);
    return head;
}

Node *deleteKthNode(Node *head, int k){
    if(head == nullptr) return nullptr;
    
    Node *temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(count==k) break; // is this condition is true, temp will store kth elem
        temp=temp->next;
    }

    Node* backElem = temp->back;
    Node* nextElem = temp->next;

    // single element DLL
    if(backElem == nullptr && nextElem == nullptr) {
        free(temp);
        return nullptr;
    }
    // back elem null (delete head)
    else if(backElem == nullptr){
        return deleteHead(head);
    }
    // next elem null (delete tail)
    else if(nextElem == nullptr){
        return deleteTail(head);
    }

    temp->back = nullptr;
    temp->next = nullptr;
    free(temp);

    backElem->next = nextElem;
    nextElem->back = backElem;


    return head;
}

void deleteNode(Node* given){
    Node *prevElem=given->back;
    Node* nextElem = given->next;

    // edge case
    if(nextElem==nullptr){
        prevElem->next = nullptr;
        given->back=nullptr;
        free(given);
        return;
    }

    prevElem->next=nextElem;
    nextElem->back = prevElem;

    given->next = nullptr;
    given->back = nullptr;
    free(given);
}

int main(){
    vector<int> arr = {2,3,4,1};
    Node *head = arrayToDLL(arr);

    // traverseDLL(head);
    // Node* newHead = deleteHead(head);
    // traverseDLL(newHead);
    
    // traverseDLL(head);
    // Node * newNode = deleteTail(head);
    // traverseDLL(head);

    // traverseDLL(head);
    // Node * newNode = deleteKthNode(head,3);
    // traverseDLL(newNode);
    
    traverseDLL(head);
    deleteNode(head->next->next);
    traverseDLL(head);


    return 0;
}