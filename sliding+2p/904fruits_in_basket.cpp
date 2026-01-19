#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr){
    int maxCount = 0;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        set<int> st;
        for(int j = i;j<n;j++){
            st.insert(arr[j]);
            if(st.size()>2){
                break;
            }
            maxCount=max(maxCount,j-i+1);
        }
    }
    return maxCount;
}

int optimal(vector<int> &arr){
    int l = 0;
    int r = 0;
    int n = arr.size();
    int len = 0;
    unordered_map<int,int> mp;

    while(r<n){
        mp[arr[r]]++;
        // can replace this while with if also 
        while(mp.size()>2){
            mp[arr[l]]--;
            if(mp[arr[l]] == 0) mp.erase(arr[l]);
            l++;
        }
        len = max(len,r-l+1);
        r++;
    }
    return len;
}

int main(){
    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
    // cout << brute(arr);
    cout << optimal(arr);
    return 0;
}