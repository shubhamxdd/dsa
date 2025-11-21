#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node *convertArrtoLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverseLL(Node *head){
    Node *temp = head;

    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool validPalindrome(Node *head){
    Node *temp = head;
    stack<int> st;

    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;

    while(temp!=nullptr){
        // int top = st.top();
        if(st.top() != temp->data) return false;
        st.pop();
        temp=temp->next;
    }
    return true;
}


int main(){
    // vector<int> arr = {4,1,2,3};
    vector<int> arr = {1,2,3,2,1};
    Node *head = convertArrtoLL(arr);
    traverseLL(head);
    cout << validPalindrome(head) << endl;
    return 0;
}