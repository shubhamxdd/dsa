#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<pair<int, int>> st; // {current elem, current_min}

    public:
        void push(int x){
            if(st.empty()){
                st.push({x,x});
            }else {
                // int min = st.top().second;
                st.push({x, min(x, st.top().second)});
            }
        }
        void pop(){
            st.pop();
        }
        int top(){
            return st.top().first;
        }
        int getMin(){
            return st.top().second;
        }
};

int main(){
    return 0;
}