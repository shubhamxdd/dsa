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

Node *hasCycleii(Node *head){
    Node *temp = head;
    map<Node*, int> mp;

    while(temp!=nullptr){
        auto elem = mp.find(temp);
        if(elem != mp.end()) return temp;
        mp.insert({temp,1});
        temp=temp->next;
    }
    return nullptr;
}

Node *hasCycleiiOptimal(Node *head){
    // detect loop

    Node *slow = head;
    Node *fast = head;


    while(fast != nullptr && fast->next !=nullptr){
        slow = slow->next;
        fast=fast->next->next;

        if(slow == fast){
            // move slow to head and move both slow and fast by 1
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArrtoLL(arr);
    // traverseLL(head);

    Node *ans = hasCycleiiOptimal(head);

    if(ans==nullptr) cout << "no loop\n";
    else if(ans !=nullptr) cout << "yes loop";


    return 0;
}