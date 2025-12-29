#include<bits/stdc++.h>
using namespace std;

int sumOfSubarrays(vector<int> &arr){
    long long sum = 0;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        long long maxi = arr[i];
        long long mini = arr[i];
        for(int j = i+1;j<n;j++){
            maxi=max(maxi,(long long)arr[j]);
            mini=min(mini,(long long)arr[j]);
            sum+= maxi-mini;
        }
    }
    return sum;
}

int main(){
    vector<int> arr = {1,4,3,2};
    cout << sumOfSubarrays(arr) << endl;
    return 0;
}