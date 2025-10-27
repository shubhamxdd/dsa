#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int target){
    int low = 0;
    int high = arr.size()-1;
    int ans = arr.size();

    while(high>=low){
        int mid = (low+high)/2;

        if(arr[mid] >=target){
            ans = mid;
            high = mid - 1;
        } else{
            low = mid+1;
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

        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        } else{
            low = mid+1;
        }
    }
    return ans;
}

// brute
vector<int> firstLastOccurence(vector<int> arr, int target)
{
    int first = -1;
    int last = -1;

    

    for (int i = 0; i < arr.size() - 1; i++){
        if (arr[i] == target){
            if (first == -1){
                first = i;
            }
            last = i;
        }
    }
    return {first, last};
}

// better
vector<int> firstLastUsingBounds(vector<int> arr, int target){
    int lb = lowerBound(arr,target);
    int ub = upperBound(arr,target);

    if(lb == arr.size() || arr[lb] !=target ){
        return {-1,-1};
    }

    return {lb,ub-1};
}

int firstOccurenece(vector<int> arr, int target ){
    int low = 0;
    int high = arr.size()-1;
    int first = -1;

    while(high>=low){
        int mid = (low+high)/2;

        if(arr[mid] == target){
            first = mid;
            high = mid-1;
        } else if(arr[mid]>target){
            high = mid-1;
        } else{
            low = mid + 1;
        }
    }
    return first;
}
int lastOccurenece(vector<int> arr, int target ){
    int low = 0;
    int high = arr.size()-1;
    int last = -1;

    while(high>=low){
        int mid = (low+high)/2;

        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
        } else if(arr[mid]>target){
            high = mid-1;
        } else{
            low = mid + 1;
        }
    }
    return last;
}

vector<int> firstLastUsingBinarySearch(vector<int> arr, int target){
    int first = firstOccurenece(arr,target);

    if(first == -1) return {-1,-1};

    int last = lastOccurenece(arr,target);

    return {first,last};
}

int main(){
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    // vector<int> ans = firstLastOccurence(arr, 8);
    // vector<int> ans = firstLastUsingBounds(arr, 8);
    vector<int> ans = firstLastUsingBinarySearch(arr, 8);
    for (int iter : ans)
    {
        cout << iter << " ";
    }
    return 0;
}