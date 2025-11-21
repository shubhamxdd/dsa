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

bool detectCycle(Node *head){
    if(head == nullptr || head->next == nullptr) return head;
    Node *temp = head;
    map<Node*,int> mp;

    while(temp!=nullptr){
        auto elem = mp.find(temp);
        if(elem != mp.end()) return true;
        mp.insert({temp,1});
        temp=temp->next;
    }
    return false;
}

bool detectCycleOptimal(Node *head){
    if(head == nullptr || head->next == nullptr) return false;
    // Node *temp = head;
    Node *slow = head;
    Node *fast = head;

    while(fast!=nullptr && fast->next!=nullptr){
        // if(fast->next==nullptr) break;
        // move pointers
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArrtoLL(arr);
    // traverseLL(head);

    // Create cycle: make last node point to head
    // Node *temp = head;
    // while(temp->next != nullptr){
    //     temp = temp->next;  // Go to last node
    // }
    // temp->next = head;  // Create cycle: 5 → 1

    // bool doesLoopExist = detectCycle(head);
    // cout << doesLoopExist;  // Expected: 1 (true)
    // DON'T call traverseLL - it will infinite loop!

    bool doesLoopExist = detectCycleOptimal(head);
    cout << doesLoopExist ;

    return 0;
}