#include<bits/stdc++.h>
using namespace std;


int brute(vector<int> &arr){
    int n = arr.size();
    int maxArea = 0;

    for(int i = 0;i<n;i++){
        for(int j = i + 1;j<n;j++){
            int h = min(arr[i],arr[j]);
            int w = (j-i);
            int area = h*w;

            maxArea = max(area,maxArea);
        }
    }
    return maxArea;
}

int main(){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    cout<<brute(arr);
    return 0;
}