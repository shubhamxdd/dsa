#include <bits/stdc++.h>
using namespace std;

pair<int,int> brute(vector<vector<int>> &matrix,int target){
    int rows = matrix.size();
    int cols = matrix[0].size();

    int tgt_row = -1;
    int tgt_col = -1;

    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(matrix[i][j] == target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}


int binarySearch(vector<int> nums, int target){
    int low = 0;
    int high = nums.size()-1;

    while(high>=low){
        int mid = (low+high)/2;

        if(nums[mid] == target) return mid;
        else if (nums[mid]>=target){
            // eliminate right
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return -1;
}

pair<int,int> better(vector<vector<int>> &matrix,int target){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i = 0;i<rows;i++){
        int val = binarySearch(matrix[i],target);
        if(val!=-1) return make_pair(i,val);
    }
    return {-1,-1};

}

pair<int,int> optimal(vector<vector<int>> &matrix,int target){
    int rows = matrix.size();
    int cols = matrix[0].size();

    int curr_row = 0;
    int curr_col = cols - 1;

    while(curr_row<rows && curr_col >= 0){
        if(matrix[curr_row][curr_col] == target) return make_pair(curr_row,curr_col);
        else if(matrix[curr_row][curr_col] >= target){
            // eliminate col
            curr_col--;
        }else{
            curr_row++;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    // pair<int,int> ans = brute(matrix,19);
    pair<int,int> ans = optimal(matrix,6);
    cout << ans.first << " " << ans.second << endl;


    return 0;
}