#include<bits/stdc++.h>
using namespace std;


vector<int> nextGreaterElementOptimal(vector<int>& arr) {
    // vector<int> ansArr(arr.size(),-1);
    vector<int> ansArr(arr.size(), 0);
    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            ansArr[i] = 0;
        } else {
            ansArr[i] = st.top();
        }
        st.push(i);
    }
    return ansArr;
}
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> arr = nextGreaterElementOptimal(temperatures);
    vector<int> tempArr (n);

    for(int i = 0;i<n;i++){
        if(arr[i]-i<=0) tempArr[i]=0;
        else tempArr[i] = arr[i]-i;
    }
    return tempArr;
}


int main(){
    vector<int> arr = {30,40,50,60};
    vector<int> ngeArr = nextGreaterElementOptimal(arr);
    for(int iter:arr) cout << iter << " ";
    cout << endl;
    for(int iter:ngeArr) cout << iter << " ";

    return 0;
}