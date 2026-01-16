#include<bits/stdc++.h>
using namespace std;

int maxConseqOnesBrute(vector<int> &arr,int k){
    int maxLen = 0;
    for(int i = 0;i<arr.size();i++){
        int zeros = 0;
        for(int j = i;j<arr.size();j++){
            if(arr[j] == 0) zeros++;
            if(zeros>k){
                break;
            }else{
                int len = j-i+1;
                maxLen=max(len,maxLen);
            }
        }
    }
    return maxLen;
}



int main(){
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    cout << maxConseqOnesBrute(arr,2);
    return 0;
}