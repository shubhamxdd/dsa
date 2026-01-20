#include <bits/stdc++.h>
using namespace std;

/*
vector<int> bubbleSort(vector<int> &arr){
    vector<int> sortedArr = arr;
    
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr.size()-i-1;j++){
            if(sortedArr[j]>sortedArr[j+1]){
                swap(sortedArr[j], sortedArr[j+1]);
            }
        }
    }
    return sortedArr;
}
*/

vector<int> brute(vector<int> &arr, int target){
    for(int i = 0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[i] + arr[j] == target) return {i, j};
        }
    }
    return {-1,-1};
}

vector<int> better(vector<int> &arr, int target){
    vector<int> arrCopy = arr;
    sort(arrCopy.begin(),arrCopy.end());

    int l = 0;
    int r = arr.size() - 1;
    int sum = 0;
    int num1 = -1;
    int num2 = -1;
    

    while(l<r){
        int sum = arrCopy[l]+arrCopy[r];
        if(sum == target){
            num1 = arrCopy[l];
            num2 = arrCopy[r];
            break;
        }
        
        if(sum > target)r--;
        else l++;
    }
    if(num1 == -1 || num2 == -1) return {-1, -1};
    // find arr[l] and arr[r]'s index in og array and return that

    int idx1 = -1;
    int idx2 = -1;
    
    for(int i = 0;i<arr.size();i++){
        if(arr[i] == num1 && idx1 == -1) idx1=i;
        else if(arr[i] == num2 && idx2 == -1) idx2 = i;
    }

    return {idx1,idx2};
}

vector<int> optimal(vector<int> &arr, int target){
    // hashing
    unordered_map <int,int> hashmap; 

    for(int i = 0;i<arr.size();i++){
        int firstElem = arr[i];
        int reqSum = target-arr[i];

        if(hashmap.find(reqSum) != hashmap.end()){
            return {i,hashmap[reqSum]};
        }
        // put it in map
        hashmap[firstElem] = i;
    }
    return {-1, -1};
}

int main(){
    vector<int> arr = {2,7,11,15};
    // vector<int> ans = brute(arr,9);
    // cout << "{ ";
    // for(int elem: ans){
    //     cout << elem << " " ;
    // }
    // cout << "}";

    // vector<int> ans = better(arr,9);
    // cout << "{ ";
    // for(int elem: ans){
    //     cout << elem << " " ;
    // }
    // cout << "}";
    vector<int> ans = optimal(arr,9);
    cout << "{ ";
    for(int elem: ans){
        cout << elem << " " ;
    }
    cout << "}";


    // vector<int> arr1 =  {4,5,1,31,51,7,5,1};
    // vector<int> sortedArr = bubbleSort(arr1);
    // for(int iter:sortedArr){
    //     cout << iter << " ";
    // }


    return 0;
}