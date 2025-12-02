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

list<pair<int,int>> findPairWithGivenSumBrute(Node *head, int sum){
    Node *temp1 = head;
    list<pair<int,int>> res;
    
    while(temp1!=nullptr){
        Node *temp2 = temp1->next;
        while(temp2!=nullptr && temp1->data + temp2->data <=sum){
            if(temp1->data + temp2->data == sum){
                res.push_back({temp1->data,temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return res;
}

Node *findTailDLL(Node *head){
    Node *temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    return temp;
}

list<pair<int,int>> findPairWithGivenSumOptimal(Node *head, int sum){
    Node *left = head;
    Node *right = findTailDLL(head);
    list<pair<int,int>> ls;

    while(left->data < right->data){
        if(left->data + right->data == sum){
            ls.push_back({left->data,right->data});
            left=left->next;
            right=right->back;
        }else if(left->data + right->data > sum){
            right=right->back;
        }else {
            left=left->next;
        }
    }
    return ls;
}


int main(){
    vector<int> arr = {1,2,3,4,9};
    Node *head = arrayToDLL(arr);
    traverseDLL(head);

    // list<pair<int,int>> res = findPairWithGivenSumBrute(head,5);
    list<pair<int,int>> res = findPairWithGivenSumOptimal(head,5);
    for(auto p: res){
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }

    return 0;
}