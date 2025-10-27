#include <bits/stdc++.h>
using namespace std;

int binarySearchIteative(vector<int> arr, int target){
        int low = 0;
        int high = arr.size()-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(target == arr[mid]) return mid;
            else if (target > arr[mid]) low = mid +1; // tgt in left of mid
            // tgt in right of mid
            else high = mid -1; 
        }
        return -1;
}

int binarySearchRecursive(vector<int> nums, int low, int high, int target){
    if(low>high) return -1;
    int mid = (low+high)/2;

    if(nums[mid] == target) return mid;
    else if(target>nums[mid]) return binarySearchRecursive(nums,mid+1, high,target); // low = mid + 1 // search on right side of target
    else return binarySearchRecursive(nums,low,mid-1,target); // high = mid -1 // search on left side of target
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int target = 5;
    // int ans = binarySearchIteative(arr, target);
    // cout << ans << endl;
    int ans = binarySearchRecursive(arr,0,arr.size()-1,target);
    cout << ans << endl;

    
    return 0;
}