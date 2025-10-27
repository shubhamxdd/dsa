#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> arr, int target){
    int low = 0;
    int high = arr.size()-1;
    int ans = arr.size();

    while(high>=low){
        int mid = (low+high)/2;
        
        if(arr[mid]>target){
            ans = mid; // ans can be mid
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return ans;
}


int floor_m(vector<int> &arr, int target){
    int low = 0;
    int high = arr.size()-1;
    int ans = arr.size();

    while(high>=low){
        int mid = (low+high)/2;
        if(arr[mid] <= target){
            ans = mid;
            low = mid+1;
        }else {
            high = mid - 1;
        }
    }
    return arr[ans];
}
int ceil_m(vector<int> &arr, int target){
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();
    while (high>=low){
        int mid = (low+high) / 2;
        if(arr[mid]>=target){
            ans = mid;
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return arr[ans];
    
}

void floorAndCeil(vector<int> arr, int target){
    cout << "Floor: ";
    cout << floor_m(arr,target) << endl;
    cout << "Ceil: ";
    cout << ceil_m(arr,target) << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
    // cout << lowerBound(arr, 4) << endl;
    // cout << upperBound(arr, 7) << endl;
    // cout << lower_bound(arr.begin(), arr.end(), 3) - arr.begin();
    floorAndCeil(arr,4);

    return 0;
}