#include <bits/stdc++.h>
using namespace std;

void getAllCombinationSum(vector<int> &arr, int index, vector<int> &currentCombination, vector<vector<int>> &answers, int target, set<vector<int>> &st){
    if(index==arr.size() || target < 0){
        return;
    }
    if(target == 0){
        // found a answer
        // check if it exist in set or not, if not push back in both answer and set
        if(st.find(currentCombination) == st.end()){
            // means not exist
            st.insert(currentCombination);
            answers.push_back(currentCombination);
        }
        return;
    }

    // recursion call
    // 3 cases
    // include, include multiple times, not include
    currentCombination.push_back(arr[index]);
    // include
    getAllCombinationSum(arr, index+1, currentCombination, answers,target-arr[index],st);
    // include multiple times
    getAllCombinationSum(arr, index, currentCombination, answers,target-arr[index],st);
    // not include
    // backtrack first
    currentCombination.pop_back();
    getAllCombinationSum(arr, index+1, currentCombination,answers, target,st);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    // to track unique values use set
    set<vector<int>> sett;
    vector<vector<int>> ans;
    vector<int> currAns; // current combination

    getAllCombinationSum(candidates, 0, currAns, ans, target, sett);
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