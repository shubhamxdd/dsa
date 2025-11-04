#include <bits/stdc++.h>
using namespace std;

class Node {
    // private:
    public:
        int data;
        Node *next;
        // construcntor
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

int lengthOfLL(Node* head){
    Node *temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

// check if element exists in LL or not
bool searchInLL(Node* head, int val){
    Node *temp = head;

    while(temp){
        if(temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    // int x = 4;
    // int *y = &x;
    // cout << y; // prints address
    vector<int> arr {2,1,3,8};
    // Node *y = new Node(arr[0],nullptr);
    // cout << y;
    Node* headOfLL = convertArrtoLL(arr);

    Node *headkaNext = headOfLL->next;
    // cout << headkaNext->next->data;
    traverseLL(headOfLL);

    cout << "Length of Linked List is: " << lengthOfLL(headOfLL) << endl;
    cout << searchInLL(headOfLL,3) << endl;
    cout << searchInLL(headOfLL,9) << endl;

    return 0;
}