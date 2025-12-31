#include<bits/stdc++.h>
using namespace std;

vector<int> findPreviousGreaterElement(vector<int> &arr){
    int n = arr.size();
    vector<int> pgeArr(n);
    stack<int> st;


    for(int i = 0;i<n;i++){
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        pgeArr[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pgeArr;
}

vector<int> findStockSpan(vector<int> &arr){
    int n = arr.size();
    vector<int> spanArr(n);
    vector<int> pgeArr = findPreviousGreaterElement(arr);

    for(int i = 0;i<n;i++){
        spanArr[i]=i-pgeArr[i];
    }
    return spanArr;
}


int main(){
    vector<int> arr = {100,80,60,70,60,75,85};
    vector<int> ansArr = findStockSpan(arr);

    for(int iter:arr) cout << iter << " ";
    cout << endl;
    for(int iter:ansArr) cout << iter << " ";
    return 0;
}