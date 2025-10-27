#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    // single element array
    if(n == 1) return 0;
    // check first element
    // 0 index element is strictly greater than its left (out of bound element, assume -Infinity)
    if(nums[0]>nums[1]) return 0;
    // check last element
    // last index element is strictly greater than its right (out of bounds, assume -Infinity)
    if(nums[n-1]>nums[n-2]) return (n-1);

    // perform binary search is any above is not true

    int low = 1;
    int high = n-2;

    while(high>=low){
        int mid = (low+high)/2;

        // check is mid element is peak
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;

        // if mid is not peak, eliminate search space

        // increasing curve/order
        // peak is on right
        // eliminate left
        else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]) low = mid + 1;

        // decreasing curve/order
        // peak is in left
        // eliminate right
        else if(nums[mid]>nums[mid+1] && nums[mid]<nums[mid-1]) high = mid - 1;
        // valley case
        else{
            // can go either side
            // move to left
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << findPeakElement(nums) << endl;
    return 0;
}