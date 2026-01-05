#include <bits/stdc++.h>
using namespace std;

void printNums(int n){
    if(n==1) {
        cout << 1 << endl;
        return;
    }
    cout << n << endl;
    printNums(n-1);
}

int factorial(int n){
    if(n==0) return 1;
    return n * factorial(n-1);
}

int summ(int n){
    if(n==1) return 1;
    return n+summ(n-1);
}

int summ2(int currSum, int n){
    if(n==0) return currSum;
    return summ2(currSum+n, n-1);
}

int fibonacci(int n){
    if(n==0||n==1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

bool isSorted(vector<int> &arr, int n){
    if(n==0||n==1) return true;
    return arr[n-1] >= arr[n-2] && isSorted(arr,n-1);
}


void printSubsetsRecursive(vector<int> &arr,vector<int> &ans,int i){
    if(i==arr.size()) {
        // print
        for(int val:ans){
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[i]);
    printSubsetsRecursive(arr,ans,i+1);
    ans.pop_back();
    printSubsetsRecursive(arr,ans,i+1);
}

// leetcode 78
void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets){
    if(i==nums.size()){
        // store in array
        allSubsets.push_back({ans});
        return;
    }
    // include
    ans.push_back(nums[i]);
    getAllSubsets(nums,ans,i+1,allSubsets);
    // exclude
    ans.pop_back();
    getAllSubsets(nums,ans,i+1,allSubsets);
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(nums,ans,0,allSubsets);
    return allSubsets;
}

int main(){
    vector<int> arr = {1,2,3};
    // vector<int> ans;
    // printSubsetsRecursive(arr,ans,0);

    vector<vector<int>> allSubsetss =  subsets(arr);

    for(vector<int> subset:allSubsetss){
        cout << "{ ";
        for(int val:subset){
            cout << val << " ";
        }
        cout << "}" << endl;
    }

    



    // printNums(10);
    // cout << factorial(4);
    // cout << summ(4);
    // cout << summ2(0,4);
    // cout << fibonacci(6);
    // vector<int> arr = {1,2,3,4,5};
    // cout << isSorted(arr,arr.size()) << endl;
    // vector<int> arr1 = {1,3,2,4,5};
    // cout << isSorted(arr1,arr1.size()) << endl;



    return 0;
}