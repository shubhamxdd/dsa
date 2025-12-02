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

Node *sort012Brute(Node *head){
    Node *temp = head;
    int count0=0,count1=0,count2=0;

    // count
    while(temp){
        if(temp->data == 0) count0++;
        else if(temp->data == 1) count1++;
        else count2++;
        temp=temp->next;
    }

    // replace
    temp=head;

    while(count0){
        count0--;
        temp->data=0;
        temp=temp->next;
    }
    while(count1){
        count1--;
        temp->data=1;
        temp=temp->next;
    }
    while(count2){
        count2--;
        temp->data=2;
        temp=temp->next;
    }
    return head;
}

Node *sort012(Node *head){
    if(head==nullptr || head->next == nullptr) return head;
    Node *temp = head;
    Node *dummyNode0 = new Node(-1);
    Node *zero = dummyNode0;
    Node *dummyNode1 = new Node(-1);
    Node *one = dummyNode1;
    Node *dummyNode2 = new Node(-1);
    Node *two = dummyNode2;


    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero=zero->next;
        }else if(temp->data == 1){
            one->next = temp;
            one=one->next;
        }else {
            two->next = temp;
            two=two->next;
        }
        temp=temp->next;
    }

    zero->next = (dummyNode1->next)? dummyNode1->next:dummyNode2->next;
    one->next = dummyNode2->next;
    two->next = nullptr;

    Node *ans = dummyNode0->next;
    delete dummyNode0;
    delete dummyNode1;
    delete dummyNode2;

    return ans;
}
int main(){
    vector<int> arr = {1,0,1,2,0,2,1};
    Node *head = convertArrtoLL(arr);
    traverseLL(head);

    // Node *sorted=sort012Brute(head);
    // traverseLL(sorted);
    Node *sorted=sort012(head);
    traverseLL(sorted);

}