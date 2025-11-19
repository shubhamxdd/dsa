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

Node *middleOfLLUsingCount(Node *head){
    int lengthofLL = 0;

    Node *temp = head;
    while(temp){
        lengthofLL++;
        temp=temp->next;
    }
    cout << "Length of LL is : " << lengthofLL << endl;
    

    temp = head; // reset head position
    int midIdx = (((lengthofLL)/2)+1);
    
    // cout << "Mid idx of LL is : " << midIdx << endl;

    // so traverse LL till middle element and return its Node

    while(midIdx!=1){ // taking 1 because 0 lene pe wo ek element aage se de raha h
        midIdx--;
        temp=temp->next;
    }
    return temp;

}

Node *middleOfLLOptimal(Node *head){
    Node *slow = head;
    Node *fast = head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr = {4,2,1,3};
    Node *head = arrayToLL(arr);
    traverseLL(head);
    // Node *ans = middleOfLLUsingCount(head);
    // traverseLL(ans);

    Node *ans = middleOfLLOptimal(head);
    traverseLL(ans);



    // vector<int> arr1 = {4,2,1,3,5};
    // Node *head1 = arrayToLL(arr1);
    // traverseLL(head1);
    // middleOfLLUsingCount(head1);


    return 0;
}