#include <bits/stdc++.h>
using namespace std;

int countRotations(vector<int> nums){
    // find minimum element and its index is answer

    int low = 0;
    int high = nums.size() - 1;
    int minVal = INT_MAX;
    int minValIdx = -1;

    while(high>=low){
        int mid = (low+high)/2;

        // search space is sorted
        if(nums[high]>=nums[low]){
            if(nums[low]<=minVal){
                minVal = nums[low];
                minValIdx = low;
            }

            break;
        }

        // left part is sorted
        if(nums[mid]>=nums[low]){

            if(nums[low]<=minVal){
                minVal = nums[low];
                minValIdx = low;
            }

            low = mid + 1;
        }
        // right part is sorted
        else{
            if(nums[mid]<=minVal){
                minVal = nums[mid];
                minValIdx = mid;
            }
            high = mid - 1;
        }
    }
    return minValIdx;
}

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << countRotations(nums); // output 4
    return 0;
}