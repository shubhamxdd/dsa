#include<bits/stdc++.h>
using namespace std;

int repeatedNTimesBrute(vector<int> &arr){
    int n = arr.size();

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]==arr[j]) return arr[i];
        }
    }
    return -1;
}

int repeatedNTimesOptimal(vector<int> &arr){
    unordered_map<int,int> hashmap;
    // value, count
    int n = arr.size();

    for(int i = 0;i<n;i++){
        // // print hashmap
        // for(auto &pair: hashmap){
        //     cout << pair.first << " " << pair.second << endl;
        // }
        // cout << endl;
        // cout << endl;
        if(hashmap.find(arr[i]) != hashmap.end()){
            // means element exists
            return arr[i];
        }else{
            hashmap[arr[i]]++;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,3};
    // cout << repeatedNTimesBrute(arr) << endl;
    cout << repeatedNTimesOptimal(arr) << endl;
    return 0;
}