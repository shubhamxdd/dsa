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
        Node *temp = new Node(arr[i]); // to store node temporarily, create new node for each element
        mover->next = temp;
        // move mover one step ahead
        // mover = mover->next;
        // or
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

Node *mergeTwoListsBrute(Node *list1, Node *list2){
    Node *temp1 = list1;
    Node *temp2 = list2;

    vector<int>arr;

    while(temp1){
        arr.push_back(temp1->data);
        temp1=temp1->next;
    }
    while(temp2){
        arr.push_back(temp2->data);
        temp2=temp2->next;
    }

    sort(arr.begin(),arr.end());

    Node *head = convertArrtoLL(arr);

    return head;

}

Node *mergeTwoLists(Node *list1, Node *list2){
    Node *head1=list1;
    Node *head2=list2;

    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while(head1!=nullptr && head2!=nullptr){
        if(head1->data < head2->data){
            temp->next=head1;
            temp=head1;
            head1=head1->next;
        }else {
            temp->next=head2;
            temp=head2;
            head2=head2->next;
        }
    }
    if(head1) temp->next=head1;
    else temp->next=head2;
    return dummyNode->next;
}

int main(){
    // vector<int> arr1 = {4,2,1,3,5};
    // vector<int> arr2 = {6,9,8,7};
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {6,7,8,9};
    Node *head1 = convertArrtoLL(arr1);
    Node *head2 = convertArrtoLL(arr2);
    traverseLL(head1);
    traverseLL(head2);

    Node *sortedHead = mergeTwoLists(head1,head2);
    traverseLL(sortedHead);


    return 0;
}