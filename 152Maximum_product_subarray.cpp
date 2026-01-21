#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr){
    int n = arr.size();
    int maxProduct = INT_MIN;
    for(int i = 0;i<n;i++){
        int prod = arr[i];
        for(int j = i+1;j<n;j++){
            prod*=arr[j];
            maxProduct = max(maxProduct,prod);
        }
    }
    return maxProduct;
}

int optimal(vector<int> &nums){
    int n = nums.size();
    int maxi = INT_MIN;
    int prefix = 1;
    int suffix = 1;

    for(int i = 0;i<n;i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix*=nums[i];
        suffix*=nums[n-i-1];
        maxi = max(maxi,max(prefix,suffix));
    }
    return maxi;
}

int main(){
    vector<int> arr = {2,3,-2,4};
    // cout << brute(arr);
    cout << optimal(arr);
    return 0;
}