#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int>& arr) {
    int n = arr.size();
    int maxLen = 0;
    
    unordered_map<int,int> mp; 
    
    // vector<int> prefArr(n);
    // prefArr[0] = arr[0];
    
    // for(int i = 1;i<n;i++){
    //     prefArr[i] = arr[i] + prefArr[i-1];
    // }
    
    
    int cumSum = 0;

    for(int i = 0;i<n;i++){
        cumSum+=arr[i];
        int curr = cumSum;
        // same as subarr sum k but k = 0; 
        // if(k == 0) found calculate and update length of subarray
        
        if(curr == 0){
            maxLen = max(maxLen,i+1);
        }
        
        // need to make elem zero
        int need = curr - 0;
        
        if(mp.find(need) != mp.end()){
            maxLen = max(maxLen, i - mp[need]);
        }
        
        if(mp.find(need) == mp.end()){
            // if doesnt exist then push it
            mp[need] = i;
        }
        
    }
    
    return maxLen;
}

int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxLength(arr);
    return 0;
}