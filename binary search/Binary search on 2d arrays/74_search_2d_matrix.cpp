#include <bits/stdc++.h>
using namespace std;

bool searchMatrixBrute(vector<vector<int>>&matrix, int target){
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
}


bool binarySearch(vector<int> nums, int target){
    int low = 0;
    int high = nums.size()-1;

    while(high>=low){
        int mid = (low+high)/2;

        if(nums[mid] == target) return true;
        else if (nums[mid]>=target){
            // eliminate right
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return false;
}


bool searchMatrixBetter(vector<vector<int>>&matrix, int target){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i = 0;i<rows;i++){
        if(matrix[i][0]<=target && matrix[i][cols-1]>=target){
            // do binary search
            return binarySearch(matrix[i],target);
        }
    }
    return false;
}

bool searchMatrixOptimal(vector<vector<int>> &matrix, int target){
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0;
    int high = ((rows*cols)-1);

    while(high>=low){
        int mid = (low+high)/2;
        // convert mid index to a 2d coordinate
        int row = mid/cols;
        int col = mid % cols;

        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] >= target){
            // eliminate right
            high = mid - 1;
        }else{
            // eliminate left
            low = mid + 1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    cout << searchMatrixBetter(matrix,23) << endl;
    return 0;

}