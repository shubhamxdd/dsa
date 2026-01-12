#include <bits/stdc++.h>
using namespace std;

void getAllCombinationSum(vector<int> &arr, int index, vector<int> &currentCombination, vector<vector<int>> &answers, int target){
    if(index==arr.size() || target < 0){
        return;
    }
    if(target == 0){
        // found
        answers.push_back(currentCombination);
        return;
    }

    // recursion call
    // 3 cases
    // include, include multiple times, not include
    currentCombination.push_back(arr[index]);
    // include
    getAllCombinationSum(arr, index+1, currentCombination, answers,target-arr[index]);
    // include multiple times
    getAllCombinationSum(arr, index, currentCombination, answers,target-arr[index]);
    // not include
    // backtrack first
    currentCombination.pop_back();
    getAllCombinationSum(arr, index+1, currentCombination,answers, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    vector<int> currAns; // current combination

    getAllCombinationSum(candidates, 0, currAns, ans, target);
    return ans;

}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> combinations = combinationSum(arr,8);

    for(vector<int> combination: combinations){
        for(int val: combination){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}