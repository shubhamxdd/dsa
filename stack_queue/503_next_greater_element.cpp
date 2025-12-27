#include<bits/stdc++.h>
using namespace std;

vector<int> ngtii(vector<int> &arr){
    int len = arr.size();
    vector<int> ansArr (len) ;
    stack<int> s;
    for(int i = 2*len-1;i>=0;i--){
        while(!s.empty() && arr[s.top()] <= arr[i%len]){
            s.pop();
        }
        if(s.empty()){
            ansArr[i%len] = -1;
        }else {
            ansArr[i%len] = arr[s.top()];
        }
        s.push(i%len);
    }
    
    
    return ansArr;
}

int main(){
    vector<int> arr = {6,0,8,1,3};
    vector<int> ans = ngtii(arr);
    
    for(int val:ans){
        cout << val <<" ";
    }
    return 0;
}