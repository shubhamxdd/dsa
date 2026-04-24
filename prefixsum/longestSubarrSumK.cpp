#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    // code here
    int n = arr.size();
    
    int maxDist = 0;
    
    unordered_map<int,int> mp; // stores currSum, its last seen index
    
    // prefix array
    // vector<int> prefArr(n);
    // prefArr[0] = arr[0];
    
    // for(int i = 1;i<n;i++){
    //     prefArr[i] = arr[i] + prefArr[i-1];
    // }
    
    // loop over it 
    int currSum = 0;
    for(int i = 0;i<n;i++){
        currSum += arr[i];
        
        if(currSum == k) maxDist = max(maxDist,i+1);
        
        int need = currSum - k;
        
        // if need exist in map, update distnace
        // else push it
        
        if(mp.find(need) != mp.end()){
            maxDist = max(maxDist, i - mp[need]);
        }
        
        if(mp.find(currSum) == mp.end()) mp[currSum] = i;
        
    }
    return maxDist;
}



int main(){
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << longestSubarray(arr, k);
    return 0;
}