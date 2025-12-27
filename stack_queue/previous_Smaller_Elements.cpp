#include<bits/stdc++.h>
using namespace std;

vector<int> PSE(vector<int> &arr){
    int n = arr.size();
    vector<int> ansArr(n,-1);

    for(int i = 0;i<=n;i++){
        for(int j = i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                ansArr[i] = arr[j];
                break;
            }
        }
    }
    return ansArr;
}

vector<int> PSEOptimal(vector<int> &arr){
    int n = arr.size();
    vector<int> ansArr(n,-1);
    stack<int> st;

    for(int i = 0;i<n; i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(st.empty()) ansArr[i] = -1;
        else ansArr[i] = st.top();
        st.push(arr[i]);
    }
    return ansArr;
}

int main(){
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = PSEOptimal(arr);
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
}