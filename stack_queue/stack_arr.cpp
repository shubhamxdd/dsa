#include <bits/stdc++.h>
using namespace std;

class StackUsingArr {
    int top = -1;
    int st[10];

    public:
        void push(int n){
            if(top >=9){
                cout << "Overflow" << endl;
                return;
            }
            top++;
            st[top]=n;
        }
        void pop(){
            if(top == -1){
                cout << "Empty stack" << endl;
                return;
            }
            top--;
        }
        int topV(){
            if(top == -1){
                cout << "Empty stack" << endl;
                return -1;
            }
            return st[top];
        }
        int size(){
            return top+1;
        }
};

int main(){
    StackUsingArr st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.topV() << endl;
    cout << st.size() << endl;
    
    st.pop();
    st.pop();
    cout << st.topV() << endl;
    
    return 0;
}