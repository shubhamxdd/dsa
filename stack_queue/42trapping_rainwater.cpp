#include <bits/stdc++.h>
using namespace std;

int trappingRainwaterBrute(vector<int> &arr){
    int total = 0;
    int n = arr.size();

    for(int i = 0;i<n;i++){
        int leftMax = 0;
        int rightMax = 0;

        for(int j = 0;j<i;j++){
            leftMax = max(leftMax, arr[j]);
        }

        for(int j = i+1;j<n;j++){
            rightMax = max(rightMax, arr[j]);
        }

        if(arr[i]< leftMax && arr[i]<rightMax){
            total+= min(leftMax, rightMax) - arr[i];
        }
    }
    return total;
}

int trappingRainwaterBetter(vector<int> &arr){
    int total = 0;
    int n = arr.size();

    // compute prefix max of array
    vector<int> prefixArr(n);

    prefixArr[0] = arr[0];
    for(int i = 1;i<n;i++){
        prefixArr[i] = max(prefixArr[i-1],arr[i]);
    }

    // compute suffix max of array
    vector<int> suffixArr(n);
    
    suffixArr[n-1] = arr[n-1];
    for(int i = n-2;i>=0;i--){
        suffixArr[i] = max(suffixArr[i+1], arr[i]);
    }

    for(int i = 0;i<n;i++){
        int leftMax = prefixArr[i];
        int rightMax = suffixArr[i];

        if(arr[i]< leftMax && arr[i]<rightMax){
            total+= min(leftMax, rightMax) - arr[i];
        }
    }
    return total;
}

int trappingRainwaterOptimal(vector<int> &arr){
    int l = 0;
    int r = arr.size() - 1;

    int lMax = 0;
    int rMax = 0;
    
    int total = 0;


    while(l<r){
        lMax = max(lMax, arr[l]);
        rMax = max(rMax, arr[r]);

        if(lMax<rMax){
            total+=lMax-arr[l];
            l++;
        }else {
            total+=rMax-arr[r];
            r--;
        }
    }
    return total;
}

int main(){
    vector<int> arr = {4,2,0,3,2,5};
    // cout<<trappingRainwaterBrute(arr)<<endl;
    // cout<<trappingRainwaterBetter(arr)<<endl;
    cout<<trappingRainwaterOptimal(arr)<<endl;
    return 0;
}