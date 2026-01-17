#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr, int k ){
    int n = arr.size();
    int count = 0;

    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum+=arr[j];
            if(sum == k) count++;
        }
    }
    return count;
}

int optimal(vector<int> &arr, int k){
    int n = arr.size();
    int count = 0;
    unordered_map<int,int> mp;
    vector<int> prefixSumArr(n);
    
    // compute prefixsum array
    prefixSumArr[0] = arr[0];
    for(int i = 1;i<n;i++){
        prefixSumArr[i] = prefixSumArr[i-1] + arr[i];
    }

    // now run a loop to find sum = k

    for(int j = 0;j<n;j++){
        if(prefixSumArr[j] == k) count++;
        // if above not true then find req and search for it in map
        int req = prefixSumArr[j] - k;
        if(mp.find(req) != mp.end()){
            // add its value to count
            count += mp[req];
        }

        if(mp.find(prefixSumArr[j]) == mp.end()){
            mp[prefixSumArr[j]] = 0;
        }
        mp[prefixSumArr[j]]++;
    }
    return count;
}

int main(){
    vector<int> arr = {9,4,20,3,10,5};
    cout << brute(arr,33) << endl;
    cout << optimal(arr,33) << endl;
    return 0;
}