#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void deleteNode(Node *node){
    Node *prev = NULL;
    while (node != NULL && node->next != NULL)
    {
        node->data = node->next->data;
        prev = node;
        node = node->next;
    }
    prev->next = NULL;
    delete (node);
}

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

int main(){
    vector<int> arr = {4,5,1,9};
    Node *head = convertArrtoLL(arr);
    cout << "Original Linked List: ";
    Node *temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    // Deleting node with value 5
    Node *nodeToDelete = head->next; // Node with value 5
    deleteNode(nodeToDelete);
    cout << "Linked List after deletion: ";
    temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    

    return 0;
}