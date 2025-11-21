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


Node *reverseLLOptimal(Node *head){
    Node *temp = head;
    Node *prev = nullptr;

    while(temp!=nullptr){
        Node *front = temp->next;
        temp->next = prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

bool validPalindromeOptimal(Node *head){
    Node *slow = head;
    Node* fast = head;

    // 1. identify middle
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. reverse second half
    Node *newHead = reverseLLOptimal(slow->next);

    // 3. check for palindrome

    Node *first = head;
    Node *second = newHead;

    while(second!=nullptr){
        if(first->data != second->data) {
            reverseLLOptimal(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLLOptimal(newHead);
    return true;
}

int main(){
    // vector<int> arr = {4,1,2,3};
    vector<int> arr = {1,2,3,2,1};
    Node *head = convertArrtoLL(arr);
    traverseLL(head);
    // cout << validPalindrome(head) << endl;
    cout << validPalindromeOptimal(head) << endl;
    return 0;
}