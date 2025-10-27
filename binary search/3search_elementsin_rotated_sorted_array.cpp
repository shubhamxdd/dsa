#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size()-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]==target) return mid; // found target, return its index

        // check if left part is sorted or not
        if(nums[mid]>=low){
            // if left sorted check if target lies in left part
            // means element lies in left part i.e. low <= tgt <=  mid
            if(target>=nums[low] && target<=nums[mid]){ 
                // tgt lies in left so eliminate right
                high = mid -1;
            }
            // target doesnt lie in left means it will lie on right
            // eliminate left
            else { 
                low = mid+1;
            }
        }
        // if left part is not sorted means right part will be 
        // check if right part sorted or not
        // else if(nums[high] => nums[mid])
        else {
            // check if element lies inside of right part
            if(target>=nums[mid] && target <= nums[high]){
                // if true, target lies on right
                // means mid <= target <= high
                // eliminate left
                low = mid+1;
            }
            // target doesnt lie om right so means it will be on left 
            // eliminate right
            else{
                high = mid - 1;
            }
        }

    }
    return -1;
}

int main(){
    // vector<int> arr = {1,2,3,4,5};
    vector<int> arr = {4,5,1,2,3};
    cout << search(arr,1);
    return 0;
}

