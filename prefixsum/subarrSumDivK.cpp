#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();

    int cnt = 0;

    unordered_map<int,int> mp; // currSum, freq
    mp[0] = 1;

    int currSum = 0;

    for(int i = 0;i<n;i++){
        currSum += nums[i];

        int rem = ((currSum % k) + k) % k;

        cnt += mp[rem];
        mp[rem]++;
    }
    return cnt;
}


int main(){
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;

    cout << subarraysDivByK(nums, k);

    return 0;
}