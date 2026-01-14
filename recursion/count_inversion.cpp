#include <bits/stdc++.h>
using namespace std;

int countInversionsBrute(vector<int> &arr){
    int n = arr.size();
    int count = 0;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[i]>arr[j] && i<j){
                count++;
            }
        }
    }

    return count;

}

int merge(vector<int> &arr,int start, int mid, int end){
    vector<int> temp;
    int i = start;
    int j= mid+1;

    int invCnt = 0;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            // means a[i]>a[j], inversion found!
            temp.push_back(arr[j]);
            invCnt+=mid-i+1;
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    //copy values in original array
    for(int idx = 0;idx<temp.size();idx++){
        arr[idx+start] = temp[idx];
    }
    return invCnt;
}

int mergeSort(vector<int> &arr, int start, int end){
    if(start<end){
        int mid = (start+end)/2;

        // left half
        int left = mergeSort(arr,start,mid);
        // right half
        int right = mergeSort(arr,mid+1,end);

        int invCnt = merge(arr,start,mid,end);
        return left+right+invCnt;
    }
    return 0;
}

int main(){
    vector<int> arr = {6,3,5,2,7};
    // cout << countInversionsBrute(arr);
    cout << mergeSort(arr,0,arr.size()-1);
    return 0;
}