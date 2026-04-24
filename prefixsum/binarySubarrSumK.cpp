#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int,int> mp;
    int cnt = 0;

    int currSum = 0;
    for(int i = 0;i<n;i++){
        currSum+=nums[i];

        if(currSum == k) cnt++;

        int need = currSum - k;

        if(mp.find(need) != mp.end()) cnt+=mp[need];
        mp[currSum]++;
    }
    return cnt;
}

int main(){
    vector<int> nums = {1,0,1,0,1};
    int k = 2;
    cout << numSubarraysWithSum(nums, k);
    return 0;
}