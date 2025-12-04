#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int d, Node *n){
            data=d;
            next=n;
        }
        Node (int d){
            data=d;
            next=nullptr;
        }
};

class qLL {
    Node *start = nullptr;
    Node *end = nullptr;
    int size = 0;

    public:
        void push(int n){
                Node *newNode = new Node(n);
                if(start==nullptr){
                    start=end=newNode;
                }else{
                    end->next=newNode;
                }
                end=newNode;
                size++;
            }
        void pop(){
            if(start==nullptr){
                return;
            }
            Node *temp=start;
            start=start->next;

            if(start==nullptr){
                end=nullptr;
            }
            delete temp;
            size--;
        }
        int topV(){
            if(start==nullptr) {
                return -1;
            }
            return start->data;
        }
        int sizeF(){
            return size;
        }
};

int main(){
    qLL q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.topV() << endl;
    cout << q.sizeF() << endl;
    q.pop();
    cout << q.topV() << endl;
    cout << q.sizeF() << endl;
    return 0;
}