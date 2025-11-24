#include<bits/stdc++.h>
using namespace std;

class stackUsingArr {
    int top=-1;
    int st[10]; // can store 10 elements only

    public: 
        void push(int n){
            // overflow check
            if(top>=10) cout << "Overflow" << endl;
            top++;
            st[top]=n;
        }
        void pop(){
            if(top == -1) cout << "Empty stack" << endl;
            top--;
        }
        int topElem(){
            if(top == -1) cout << "Empty stack" << endl;
            return st[top];
        }
        int size(){
            return top+1;
        }

};

class queueUsingArr{

    int start = -1;
    int end = -1;
    int currSize = 0;
    
    int size = 10;
    int q[10];
    
    public:
        void push(int n){
            if(currSize==size) cout << "queue full" <<endl;
            if(currSize == 0) {
                start = 0;
                end = 0;
            }else {
                end=(end+1)%size;
            }
            q[end] = n;
            currSize++;

        }
        int pop(){
            int el;
            if(currSize==0){
                // print 
                int el = q[start];
            }
            if(currSize==1){
                start=-1;
                end=-1;
            }else {
                start = (start+1)%size;
            }
            currSize--;
            return el;
        }
        int top(){
            if(currSize==0){
                // no elem
            }
            return q[start];
        }
        int sizeQ(){
            return currSize;
        }
};

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

class StackUsingLL {
    int size=0;
    Node *top = nullptr;
    
    public: 
    Node * push(int n){
        Node *newNode = new Node(n,top);
        // newNode->next=top;
        top=newNode;
        size++;
    }
    void pop(){
        Node *temp = top;
        top=top->next;
        delete temp;
        size--;
    }
    int topV(){
        return top->data;
    }
    int sizeV(){
        return size;
    }


};


Node* convertArrtoLL(vector<int> &arr){
    Node *head = new Node(arr[0]); 
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


int main(){
    // stackUsingArr st;
    // st.push(10);
    // st.push(11);
    // st.push(12);
    // st.pop();
    // cout << st.topElem() << endl;
    // cout << st.size() << endl;    

    // queueUsingArr q;

    // q.push(10);
    // q.push(20);
    // q.push(30);
    // cout << q.top() << endl;
    // cout << q.sizeQ() << endl;
    // q.pop();
    // cout << q.top() << endl;
    // cout << q.sizeQ() << endl;


    StackUsingLL st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.sizeV() << endl;
    cout << st.topV() << endl;
    
    st.pop();
    st.pop();
    
    cout << st.sizeV() << endl;
    cout << st.topV() << endl;
    
    st.push(99);
    
    cout << st.sizeV() << endl;
    cout << st.topV() << endl;



    return 0;
}