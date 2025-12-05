#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> st; // {current elem, current_min}
    long long minV = INT_MAX;

    MinStack() { minV = LLONG_MAX; }

    void push(long long x) {
        if (st.empty()) {
            minV = x;
            st.push(x);
        } else {
            if (x >= minV) { // ✅ Also fix: use >= not >
                st.push(x);
            } else {
                long long oldMin = minV;   // ✅ Save old minimum
                minV = x;                  // Update to new minimum
                st.push(2LL * x - oldMin); // ✅ Use old minimum in formula
            }
        }
    }
    void pop() {
        if (st.empty())
            return;

        long long x = st.top();
        st.pop();
        if (x < minV) {
            minV = 2 * minV - x;
        }
    }
    long long top() {
        if (st.empty())
            return -1;

        long long x = st.top();
        if (x > minV)
            return x;
        return minV;
    }
    int getMin() { return minV; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    return 0;
}