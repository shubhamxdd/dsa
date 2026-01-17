#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSumBrute(vector<int>& nums, int goal) {
    int subarrayEqualGoal = 0;
    for(int i = 0;i<nums.size();i++){
        int sum=0;
        for(int j = i;j<nums.size();j++){
            sum+=nums[j];
            if(sum == goal) {
                subarrayEqualGoal++;
            }
        }
    }
    return subarrayEqualGoal;
}


int numSubarraysWithSumBetter(vector<int> &arr, int goal){
    int prefixSum[arr.size()];
    prefixSum[0] = arr[0];
    // compute prefix array
    for(int i = 1;i<arr.size();i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    unordered_map <int,int> mp;
    int count = 0;

    for(int j = 0;j<arr.size();j++){
        if(prefixSum[j] == goal) count++;
        int val = prefixSum[j] - goal;
        // find val in map
        if(mp.find(val) != mp.end()){
            count+=mp[val];
        }
        if(mp.find(prefixSum[j]) == mp.end()){
            mp[prefixSum[j]] = 0;
        }
        mp[prefixSum[j]]++;
    }
    return count;
}

// calculates subarray with sum less that equal to goal i.e. <=goal
int numSubarraysWithSumOptimal(vector<int> &arr,int goal){
    if(goal<0) return 0;
    int r = 0;
    int l = 0;
    int n = arr.size();
    int count = 0;
    int sum = 0;

    while(r<n){
        sum+=arr[r];
        while(sum>goal){
            sum-=arr[l];
            l++;
        }
        count = count+(r-l+1);
        r++;
    }
    return count;
}

int main(){
    vector<int> arr = {1,0,1,0,1};
    // cout << numSubarraysWithSumBrute(arr,2) << endl;
    // cout << numSubarraysWithSumBetter(arr,2) << endl;
    cout << numSubarraysWithSumOptimal(arr,2) - numSubarraysWithSumOptimal(arr,2-1);
    return 0;
}