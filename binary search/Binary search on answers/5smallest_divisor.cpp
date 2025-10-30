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

int main(){
    vector<int> nums = {1,2,5,9};
    cout << brute(nums,6);
    return 0;
}