#include<bits/stdc++.h>
using namespace std;

class qArr{
    int start = -1;
    int end = -1;
    int currSize = 0;
    // int size = 10;
    int q[10];

    public:
        void push(int n){
            if(currSize==10) {
                cout << "queue full" <<endl;
                return;
            }
            if(currSize == 0) {
                start = 0;
                end = 0;
            }else{
                end=(end+1)%10;
            }
            q[end] = n;
            currSize++;
        }
        void pop(){
            int el;
            if(currSize==0){
                cout << "queue empty" << endl;
                return;
            }
            if(currSize==1){
                start=-1;
                end=-1;
            }else {
                start = (start+1)%10;
            }
            currSize--;   
        }
        int top(){
            if(currSize==0){
                cout << "queue empty" << endl;
                return -1;
            }
            return q[start];
        }
        int sizeQ(){
            return currSize;
        }
};

int main(){
    qArr q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.top() << endl;
    cout << q.sizeQ() << endl;

    q.pop();
    cout << q.top() << endl;
    cout << q.sizeQ() << endl;
    return 0;
}