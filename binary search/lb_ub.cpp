#include<bits/stdc++.h>
using namespace std;

/*
int lowerBound(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    int ans = n;

    while(high>=low){
        int mid = (low+high)/2;

        if(arr[mid] >= target){
            ans=mid;
            high=mid-1;
        }else {
            low=mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    int ans = n;

    while(high>low){
        int mid = (low+high)/2;

        if(arr[mid] >= target){
            ans=mid;
            high=mid-1;
        }else {
            low=mid+1;
        }
    }
    return ans;
}
*/

int searchInRotatedSortedArray(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(high>=low){
        int mid = (low+high)/2;
        if(arr[mid]==target) return mid;

        // left part selected
        else if(arr[mid]>target){
            // check if it lies in its range or not
            if(arr[mid]>=target  && arr[low]<=target){
                // if true then element lies in this part (left)
                // eliminate right
                high=mid-1;
            }else{
                // eliminate left (element doesnt lie in its range)
                low=mid+1;
            }
        }
        // right part selected
        else {
            // check if element lies in this part and its range
            if(arr[mid]<=target && target<=arr[high]){
                // element lies in this part (right) eliminate left
                low=mid+1;
            }else {
                high=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    // cout << lowerBound(arr,2)<<endl;
    // cout << upperBound(arr,2)<<endl;
    cout << searchInRotatedSortedArray(arr,2)<<endl;
    return 0;
}