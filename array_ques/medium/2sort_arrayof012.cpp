#include <bits/stdc++.h>
using namespace std;

// merge sort
void merge(vector<int> &arr,int low,int mid,int high){
    int left = low;
    int right = mid+1;

    vector<int> temp;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low;i<=high;i++){
        arr[i] = temp[i-low];
    }

}
void sortArrBrute(vector<int> &arr, int low, int high){
    
    if(low>=high) return;
    int mid = (low + high) / 2;

    sortArrBrute(arr,low,mid);
    sortArrBrute(arr,mid+1,high);
    merge(arr,low,mid,high);
}


void sortArrBetter(vector<int> &arr){
    // count 0 1 2
    int countZeros=0;
    int countOnes=0;
    int countTwos=0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i]==0) countZeros++;
        else if(arr[i] == 1) countOnes++;
        else if(arr[i] == 2) countTwos++;
    }

    // cout << countZeros << endl;
    // cout << countOnes << endl;
    // cout << countTwos << endl;

    // oevr ride first "countZero" values as 0
    // oevr ride next "countOnes" values as 1
    // oevr ride next "countTwos" values as 2

    for(int i = 0;i<countZeros;i++){
        arr[i] = 0;
    }
    for(int i = countZeros;i<countZeros+countOnes;i++){
        arr[i] = 1;
    }
    for(int i = countZeros+countOnes;i<countZeros+countOnes+countTwos;i++){
        arr[i] = 2;
    }
} 

void sortArrBestOptimal(vector<int> &arr){
    // 3 pointer => low mid high
    // 0 to low -1 all zero
    // low to mid-1 all ones
    // mid to high all unsorted
    // high +1 to n-1 all twos

    int low = 0;
    int mid = 0;
    int high = arr.size()-1;

    while(high>=mid){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}


int main(){
    vector<int> arr = {0,1,2,0,1,2,0,0,0,1};
    // sortArrBrute(arr,0,arr.size()-1);

    // sortArrBetter(arr);
    sortArrBestOptimal(arr);

    for(int iter:arr){
        cout << iter << " ";
    }
    return 0;
}
