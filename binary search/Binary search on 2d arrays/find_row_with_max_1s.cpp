#include <bits/stdc++.h>
using namespace std;

int findRowWithMaxOnesBrute(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int count = 0;
    int maxCount = 0;
    int rowIdx = 0;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(matrix[i][j] == 1) count++;
        }
        if(count>maxCount){
            maxCount = count;
            if(rowIdx == 0){
                rowIdx = i;
            }else rowIdx = min(rowIdx,i);
        }
    }

    return rowIdx;

}

int lowerBound(vector<int> nums,int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();

    while(high>=low){
        int mid = (low+high)/2;
        if(nums[mid]>=target){
            ans = mid;
            // eliminate right
            high = mid -1;
        }else {
            // eliminate left
            low = mid + 1;
        }
    }
    return ans; // returns index where first one is presetn
}

int findRowWithMaxOnes(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxCount = 0;
    int idx=0;

    for(int i = 0;i<rows;i++){
        int count = lowerBound(matrix[i],1);
        int numsOfOnes = matrix[i].size() - count;
        if(numsOfOnes>maxCount){
            maxCount = numsOfOnes;
            idx = i;
        }
    }
    return idx;

}

int main(){
    vector<vector<int>> matrix = {
        {0,0,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1}
    };
    // cout << findRowWithMaxOnesBrute(matrix) << endl;
    cout << findRowWithMaxOnes(matrix) << endl;
    return 0;
}