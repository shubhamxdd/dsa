#include<bits/stdc++.h>
using namespace std;

vector<int> slidingWindowBrute(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> maxArr;

    for(int i = 0;i<=n-k;i++){
        int maxi = arr[i];
        for(int j = i;j<=i+k-1;j++){
            maxi = max(maxi, arr[j]);
        }
        maxArr.push_back(maxi);
    }
    return maxArr;
}

vector<int> slidingWindowDeque(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> ansArr;
    deque<int> dq;

    for(int i = 0;i<=n-1;i++){
        if(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1) ansArr.push_back(arr[dq.front()]);
    }
    return ansArr;
}

/*
vector<int> slidingWindowOptimal(vector<int> &arr, int k){
    int n = arr.size();
    deque<int> dq;
    vector<int> resArr;

    for(int i = 0;i<k;i++){
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i = k;i<n;i++){
        resArr.push_back(arr[dq.front()]);
        // remove elem which are not part of current window
        while(dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    resArr.push_back(arr[dq.front()]);
    return resArr;

}
*/

int main(){
    vector<int> arr = {1,3,-1,-3,5,3,7,1,6};
    // vector<int> arr = {1,3,-1,-3,5,3,6,7};
    // vector<int> ans = slidingWindowBrute(arr,3);
    vector<int> ans = slidingWindowDeque(arr,3);
    // vector<int> ans = slidingWindowOptimal(arr,3);
    for(int iter:arr) cout << iter << " ";
    cout<<endl;
    for(int iter:ans) cout << iter << " ";
    return 0;
}