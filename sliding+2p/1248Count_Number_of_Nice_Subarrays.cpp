#include<bits/stdc++.h>
using namespace std;

int numberOfSubarraysBrute(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int oddCount = 0;
        for (int j = i; j < n; j++) {
            if (nums[j] % 2 == 1) oddCount++;
            if(oddCount == k) count++;
        }
    }
    return count;
}


// same as binary subarray optimal
int calculate(vector<int>& nums, int k) {
    if(k<0) return 0;
    int n = nums.size();
    int l = 0;
    int r = 0;
    int oddNums = 0;
    int count = 0;

    while(r<n){
        oddNums+=nums[r] % 2;
        while(oddNums>k){
            oddNums -= nums[l] % 2;
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}


int numberOfSubarraysOptimal(vector<int> &arr, int k){
    return calculate(arr,k) - calculate(arr,k-1);
}



int main(){
    vector<int> arr = {1,1,2,1,1};
    // cout << numberOfSubarraysBrute(arr,3);
    cout << numberOfSubarraysOptimal(arr,3);
    return 0;
}