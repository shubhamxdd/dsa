#include <bits/stdc++.h>
using namespace std;


vector<int> spiralMatrix(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    int top = 0; // row
    int left = 0; // column
    int bottom = rows-1; // row
    int right = cols-1; // column

    vector<int> ansMatrix;

    while(right>=left && bottom>=top){
        // 4 for loops
        
        // left to right
        for(int j = left;j<=right;j++){
            // cout << matrix[top][j]<<" ";
            ansMatrix.push_back(matrix[top][j]);
        }
        top++;
        
        // top to bottom
        for(int i = top;i<=bottom;i++){
            // cout << matrix[i][right]<<" ";
            ansMatrix.push_back(matrix[i][right]);
        }
        
        right--;
        
        // right to left
        if(top<=bottom){

            for (int j = right; j >= left; j--){
                // cout << matrix[bottom][j]<<" ";
                ansMatrix.push_back(matrix[bottom][j]);
            }
            bottom--;
        }
        // bottom to top
        if(left<=right){

            for(int i = bottom;i>=top;i--){
                // cout << matrix[i][left]<<" ";
                ansMatrix.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ansMatrix;

}



int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };


    vector<int> ans = spiralMatrix(matrix);

    for(int iter:ans) cout << iter << " ";


    return 0;
}