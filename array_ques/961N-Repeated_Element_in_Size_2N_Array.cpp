#include<bits/stdc++.h>
using namespace std;

int repeatedNTimes(vector<int> &arr){
    int n = arr.size();

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]==arr[j]) return arr[i];
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,3};
    cout << repeatedNTimes(arr) << endl;
    return 0;
}