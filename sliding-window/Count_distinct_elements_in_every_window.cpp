#include<bits/stdc++.h>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k) {
    // code here
    int n = arr.size();
    int i = 0;
    int j = 0;
    
    vector<int> ans;
    unordered_map<int,int> mp;
    
    while(j<n){
        // if(mp[arr[j]]){ // arr[j] exist in map, increase frequency
            mp[arr[j]]++;
        // }else{ // arr[j] not exist in map, insert it
        //     mp.insert({arr[j],1});
        // }
        
        // check if window size reached or not
        // if reached push unique elem count in ans vector
        // and move window by 1 step
        // if not reached j++
        
        if(j-i+1 == k){
            ans.push_back(mp.size());
            // move window
            mp[arr[i]]--;
            if(mp[arr[i]] <= 0) mp.erase(arr[i]);
            i++;
        }
        j++;
    }
    return ans;
}

int main(){
    vector<int> vec = {1,2,1,3,4,2,3};
    vector<int> ans = countDistinct(vec,4);
    
    for(int v: ans){
        cout << v << " ";
    }
    return 0;
}