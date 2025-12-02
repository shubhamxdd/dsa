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

Node *intersectionBrute(Node *head1, Node *head2){
    Node *t1 = head1;
    Node *t2 = head2;
    map<Node*,int> mp;

    while(t1){
        mp.insert({t1,1});
        t1=t1->next;
    }

    while(t2){
        if(mp.find(t2)!=mp.end()){
            return t2;
        }else {
            t2=t2->next;
        }
    }
    return nullptr;

}

Node *collisionPoint(Node *smallHead, Node* largeHead, int d){
    // move larger by d steps
    while(d){
        d--;
        largeHead=largeHead->next;
    }
    while(smallHead!=largeHead){
        smallHead=smallHead->next;
        largeHead=largeHead->next;
    }
    return smallHead;
}


Node *intersectionBetter(Node *head1, Node *head2){
    Node *temp1 = head1;
    Node *temp2 = head2;

    int len1 = 0;
    int len2 = 0;

    // find len of both LL

    while(temp1){
        len1++;
        temp1=temp1->next;
    }
    while(temp2){
        len2++;
        temp2=temp2->next;
    }

    // move by d steps

    if(len1>len2){
        return collisionPoint(head2,head1,len1-len2);
    }else {
        return collisionPoint(head1,head2,len2-len1);
    }
}

Node *intersectionOptimal(Node *head1, Node *head2){
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    Node *temp1 = head1;
    Node *temp2 = head2;

    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;

        if(temp1==temp2) return temp1;

        if(temp1 == nullptr) temp1=head2;
        if(temp2 == nullptr) temp2=head1;
    }
    return nullptr;
}
Node *intersectionOptimalV2(Node *head1, Node *head2){
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    Node *temp1 = head1;
    Node *temp2 = head2;

    while(temp1!=temp2){
        temp1=(temp1 == nullptr) ? head2 : temp1->next;
        temp2=(temp2 == nullptr) ? head1 : temp2->next;
    }
    return temp1;
}

int main(){
    // Create two lists that intersect
    // List 1: 1 → 2 → 3 → 4 → 5
    // List 2: 6 → 7 → 3 → 4 → 5 (intersects at node 3)
    
    // Create the common part (intersection)
    Node* intersection = new Node(3);
    intersection->next = new Node(4);
    intersection->next->next = new Node(5);
    
    // Create first list: 1 → 2 → [3 → 4 → 5]
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = intersection;  // Point to intersection
    
    // Create second list: 6 → 7 → [3 → 4 → 5]
    Node* head2 = new Node(6);
    head2->next = new Node(7);
    head2->next->next = intersection;  // Point to same intersection
    
    cout << "List 1: ";
    traverseLL(head1);
    
    cout << "List 2: ";
    traverseLL(head2);
    
    // Find intersection
    // Node* result = intersectionBrute(head1, head2);
    // Node* result = intersectionBetter(head1, head2);
    Node* result = intersectionOptimal(head1, head2);
    
    if(result != nullptr){
        cout << "Intersection at node with value: " << result->data << endl;
        cout << "Intersection point: ";
        traverseLL(result);
    } else {
        cout << "No intersection found" << endl;
    }
    
    cout << "\n--- Test Case 2: No Intersection ---\n";
    
    // Create two separate lists with no intersection
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {6, 7, 8, 9};
    
    Node* list1 = convertArrtoLL(arr1);
    Node* list2 = convertArrtoLL(arr2);
    
    cout << "List 1: ";
    traverseLL(list1);
    
    cout << "List 2: ";
    traverseLL(list2);
    
    Node* result2 = intersectionBrute(list1, list2);
    
    if(result2 != nullptr){
        cout << "Intersection at node with value: " << result2->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }
    
    return 0;
}