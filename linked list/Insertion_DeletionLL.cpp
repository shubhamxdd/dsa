#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data1, Node*next1){
            data=data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

// array to LinkedList
Node* arrayTOLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;

}

// traverse linkedList
void traverseLL(Node *headLL){
    Node* temp = headLL;
    while (temp){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

// delete from linkedList
Node* deleteHeadFromLL(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTailFromLL(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node *temp = head;
    while (temp->next->next !=NULL){
        temp = temp->next;
    }
    // got second last element
    temp->next = NULL;
    free(temp->next);
    return head;
}


/*
// k =2or 3 in this case
Node* deleteFromMidLL(Node* head,int k){
    if(head == NULL) return head; 
    Node* temp = head;
    Node* prev = NULL; // store prev of temp
    int count = 0;

    while(temp != NULL){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;

    // this prev will point to node we have to delete
    for(int i = 1;i<k;i++){
        prev = prev->next;
    }
    // temp pointer points to a node before prev
    for(int i = 1;i<k-1;i++){
        temp = temp->next;
    }
    // store next of next element in next of temp
    temp->next = temp->next->next;
    free(prev);
    return head;
}
*/   

Node* deleteKthElement(Node* head, int k){
    if(head == NULL) return head;
    Node *temp = head;
    Node *prev = NULL;
    int count = 0;
    
    if(k==1){
        head=head->next;
        delete temp;
        return head;
    }

    while(temp!=NULL){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}


Node* deleteWithValue(Node* head, int val){
    if(head == NULL) return head;
    Node *temp = head;
    Node *prev = NULL;
    // int currVal = head->data;

    if(head->data == val) {
        head=head->next;
        delete temp;
        return head;
    };

    while(temp!=NULL){
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
        // currVal = temp->data;
    }
    return head;
}


// INSERTION
Node* insertAtHead(Node* head, int elem){
    // Node *temp = head;
    // create a new node with data as elem
    // Node *newNode = new Node(elem);
    // newNode->next = head;
    // instead of 2 lines, in one line
    Node *newNode = new Node(5,head);

    return newNode;
}

Node *insertAtTail(Node *head,int elem){
    Node* temp = head;
    Node* newNode = new Node(elem); // new node with data as elem, points to NULL

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
    return head;
}


int main(){
    vector<int> arr = {4,5,3,2};
    Node * headOFLL = arrayTOLL(arr);
    traverseLL(headOFLL);
    // Node* newHead = deleteHeadFromLL(headOFLL);
    // Node *newHead = deleteTailFromLL(headOFLL);

    /*
    Node *newHead = deleteKthElement(headOFLL,1);
    traverseLL(newHead);
    */
    /*
    Node *newHead = deleteWithValue(headOFLL,4);
    traverseLL(newHead);
    */

    // Node *newHead = insertAtHead(headOFLL,9);
    // traverseLL(newHead);

    Node *newHead = insertAtTail(headOFLL,9);
    traverseLL(newHead);

    // cout << headOFLL->data;
    return 0;
}