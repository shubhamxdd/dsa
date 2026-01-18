#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int sum = nums[i];
        for (int j = i + 1; j < n; j++) {
            sum += nums[j];
            if ((sum % k) == 0)
                return true;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;  
    bool result = checkSubarraySum(nums, k);
    cout << (result ? "True" : "False") << endl;
    return 0;
}