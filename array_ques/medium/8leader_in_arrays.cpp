#include <bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int> &arr){
    vector<int> leaders;
    for(int i = 0;i<arr.size();i++){
        bool isLeader = true;
        for(int j = i+1;j<arr.size();j++){
            if(arr[j]>arr[i]){
                isLeader = false;
                break;
            }
        }
        if(isLeader==true){
            leaders.push_back(arr[i]);
        }
    }
    return leaders;
}

vector<int> optimal(vector<int> &arr){
    vector<int> leaders;
    int maxi = INT_MIN;
    for(int i = arr.size()-1;i>=0;i--){
        if(arr[i]>maxi){
            maxi = arr[i];
            leaders.push_back(arr[i]);
        }
    }
    // sort(leaders.begin(),leaders.end());
    return leaders;
}

int main(){
    vector<int> arr = {10,22,12,3,0,6};
    // vector<int> arr = {1,2,3,4,5};
    // vector<int> arr = {5,4,3,2,1};
    // vector<int> ans = brute(arr);
    vector<int> ans = optimal(arr); // 6 12 22


    for(int iter:ans) cout << iter << " ";


    return 0;
}