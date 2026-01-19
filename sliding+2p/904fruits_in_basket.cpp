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



int main(){
    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
    cout << brute(arr);
    return 0;
}