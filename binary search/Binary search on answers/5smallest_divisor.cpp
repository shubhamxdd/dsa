#include <bits/stdc++.h>
using namespace std;

int findMaxInVec(vector<int> vec){
    int max = 0;
    for(int i = 0;i<vec.size();i++){
        if(vec[i]>max) max = vec[i];
    }
    return max;
}

int brute(vector<int>& nums, int threshold) {
    int maxVal = findMaxInVec(nums);
    for(int divisor = 1;divisor<=maxVal;divisor++){
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += ceil((double)nums[i]/divisor);
        }
        if(sum<=threshold) return divisor;
    }
    return -1;
}

int compute_sum(vector<int> nums, int divisor){
    int sum = 0;
    for(int i = 0;i<nums.size();i++){
        sum +=ceil((double)nums[i]/divisor);
    }
    return sum;
}

int smallest_divisor_optimal(vector<int> nums, int threshold){
    int low = 1;
    int high = findMaxInVec(nums);
    int ans = -1;

    while(high>=low){
        int mid = (low+high)/2;
        
        int sum = compute_sum(nums,mid);

        if(sum<=threshold){
            // mid can be possible ans but we need to find minimum
            ans = mid;
            // eliminate right
            high = mid - 1;
        }else{
            // eliminate left
            low = mid + 1;
        }
    }
    return ans;
    // return low; to save space
}

int main(){
    vector<int> nums = {1,2,5,9};
    // cout << brute(nums,6);
    cout << smallest_divisor_optimal(nums,6);
    return 0;
}