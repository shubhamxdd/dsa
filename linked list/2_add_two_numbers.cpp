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

Node *addTwoLL(Node* head1, Node* head2){
    Node *t1 = head1;
    Node *t2 = head2;

    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    int carry = 0;

    while(t1!=nullptr || t2!=nullptr){
        int sum = carry;

        if(t1) sum+=t1->data;
        if(t2) sum+=t2->data;

        Node *newNode = new Node(sum % 10);
        carry=sum/10;
        temp->next = newNode;
        temp=temp->next;    
        if(t1!=nullptr) t1=t1->next;
        if(t2!=nullptr) t2=t2->next;
    }

    if(carry) {
        Node *newNode = new Node(carry);
        temp->next=newNode;
    }
    return dummyNode->next;

}

int main(){
    vector<int> arr1 = {1,2,3};
    vector<int> arr2 = {4,5};

    Node *head1 = convertArrtoLL(arr1);
    Node *head2 = convertArrtoLL(arr2);
    // traverseLL(head1);
    // traverseLL(head2);

    Node *sumHead = addTwoLL(head1,head2);
    traverseLL(sumHead);

    return 0;
}