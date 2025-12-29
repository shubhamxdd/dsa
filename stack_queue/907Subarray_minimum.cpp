#include <bits/stdc++.h>
using namespace std;

int sumOfSubarrayMinsBrute(vector<int> &arr){
    int sum = 0;
    for(int i = 0;i<arr.size();i++){
        int mini = arr[i];
        for(int j = i;j<arr.size();j++){
            mini=min(mini,arr[j]);
            sum+=mini;
        }
    }
    return sum;
}


vector<int> findNSE(vector<int> &arr){
    int n = arr.size();
    vector<int> nseArr(n);
    stack<int> st;

    for(int i = n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()) nseArr[i]=n;
        else nseArr[i]=st.top();
        st.push(i);
    }
    for(int iter: nseArr) cout << iter << " ";
    cout << endl;
    return nseArr;
}

vector<int> findPSE(vector<int> &arr){
    int n = arr.size();
    vector<int> pseArr(n);
    stack<int> st;

    for(int i = 0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()) pseArr[i]=-1;
        else pseArr[i]=st.top();
        st.push(i);
    }
    for(int iter: pseArr) cout << iter << " ";
    cout << endl;

    return pseArr;
}

int subarraySumOptimal(vector<int> &arr){
    int n = arr.size();
    long long total = 0;
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);

    for(int i = 0;i<n;i++){
        int left = i - pse[i];
        int right = nse[i]-i;
        total = (total + (right*left*1LL*arr[i])) % (1000000007);
    }
    return total;
}


int main(){
    vector<int> arr = {3,1,2,4};
    // cout << sumOfSubarrayMinsBrute(arr) << endl;
    cout << subarraySumOptimal(arr) << endl;
    return 0;
}