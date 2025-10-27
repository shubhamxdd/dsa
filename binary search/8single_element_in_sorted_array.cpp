#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    // means array contains only one element
    if(n == 1) return nums[0];
    
    // check first and second element, if not same then first is answer
    if(nums[0]!=nums[1]) return nums[0];

    // check last and second last element, if not same then 
    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    // binary search
    int low = 1;
    int high = n-2;

    while(high>=low){
        int mid = (low+high)/2;

        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];


        // left = (even,odd)
        // if mid is odd, check mid's left element with mid 
        // if true, means we are on left half, eliminate left

        if((mid%2==1 && nums[mid]==nums[mid-1]) || ((mid%2==0 && nums[mid]==nums[mid+1]))){
            low = mid+1;
        }

        // if mid is even, check mid's right element with mid
        // if true, means we are om left half, eliminate left
        // if(mid%2==0 && nums[mid]==nums[mid+1]){
        //     low = mid+1;
        // }

        // else we are on right half so
        else{
            high = mid-1;
        }
    }
    return -1;

}

int main(){
    return 0;
}