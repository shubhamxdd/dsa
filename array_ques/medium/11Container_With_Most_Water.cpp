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

int optimal(vector<int> &arr){
    int n = arr.size();
    int left = 0;
    int right = n-1;

    int maxArea = 0;

    while(right>left){
        int height = min(arr[left],arr[right]);
        int width = right-left;
        int area = height*width;

        maxArea = max(area,maxArea);

        // trim down search space
        // remove smaller element 

        if(arr[left]>arr[right]){
            right--;
        }else{
            left++;
        }
    }
    return maxArea;
}

int main(){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    // cout<<brute(arr);
    cout<<optimal(arr);
    return 0;
}