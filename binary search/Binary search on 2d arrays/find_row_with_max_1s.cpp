#include <bits/stdc++.h>
using namespace std;

int findRowWithMaxOnesBrute(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int count = 0;
    int maxCount = 0;
    int rowIdx = 0;
    for(int i = 0;i<cols;i++){
        for(int j = 0;j<rows;j++){
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

int main(){
    vector<vector<int>> matrix = {
        {0,0,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1}
    };
    cout << findRowWithMaxOnesBrute(matrix) << endl;
    return 0;
}