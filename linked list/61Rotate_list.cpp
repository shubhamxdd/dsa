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

Node *findNthNode(Node *head,int n){
    Node *temp = head;
    int k = 1;
    while(temp!=nullptr){
        if(k==n) return temp;
        k++;
        temp=temp->next;
    }
    return temp;
}

Node *rotateList(Node *head, int k){
    if(head==nullptr || k == 0) return head;
    Node *tail = head;
    int len = 1;

    while(tail->next!=nullptr){
        len++;
        tail=tail->next;
    }
    if(k % len==0) return head;
    k=k % len;

    tail->next=head;

    Node *newTail = findNthNode(head,len-k);

    head=newTail->next;
    newTail->next=nullptr;

    return head;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArrtoLL(arr);
    traverseLL(head);
    head=rotateList(head,2);
    traverseLL(head);

    return 0;
}