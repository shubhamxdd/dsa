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

int main(){
    vector<int> arr = {1,1,2,1,1};
    cout << numberOfSubarraysBrute(arr,3);
    return 0;
}