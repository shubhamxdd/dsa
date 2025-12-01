#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
    
    Node(int dataa, Node *nextt){
        data = dataa;
        next=nextt;
    }
    Node(int dataa){
        data = dataa;
        next=nullptr;
    }
};


class CircularLL{
    Node *head;
    Node *tail;
    public:
        CircularLL(){
            head=tail=nullptr;
        }

        void insertAtHead(int val){
            Node *newNode = new Node(val);
            if(head==nullptr) {
                head=tail=newNode;
                tail->next=newNode;
            }else {
                newNode->next=head;
                head=newNode;
                tail->next=head;
            }
        }

        void print(){
            if(head==nullptr) return;

            cout << head->data << "-> " ;
            Node *temp = head->next;

            while(temp!=head){
                cout << temp->data << "-> ";
                temp=temp->next;
            }
            cout << temp->data;   
        }
};


int main(){

    CircularLL cll;

    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);

    cll.print();

 
    return 0;
}