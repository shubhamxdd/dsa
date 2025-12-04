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

class stackLL {
    int size = 0;
    Node *top = nullptr;

    public:
        void push(int n){
            Node *newNode = new Node(n,top);
            top = newNode;
            size++;
        }
        void pop(){
            if(size == 0){
                cout << "Stack Underflow" << endl;
                return;
            }
            Node *temp = top;
            top=top->next;
            size--;
            delete temp;
        }
        int topV(){
            if(size == 0){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top->data;
        }
        int sizeV(){
            return size;
        }
};


int main(){
    stackLL st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.topV() << endl; // 30
    st.pop();
    cout << st.topV() << endl; // 20
    cout << st.sizeV() << endl; // 2

    


    return 0;
}