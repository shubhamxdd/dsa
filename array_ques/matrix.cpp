#include <bits/stdc++.h>
using namespace std;

pair<int, int> linearSearchMatrix(vector<vector<int>> matrix, int target)
{
    // pair<int,int> idx;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == target)
            {
                return {i, j};
                // idx.first = i;
                // idx.second = j;
            }
        }
    }
    return {-1, -1};
}

pair<int, int> returnRowMaxSum(vector<vector<int>> matrix)
{
    int maxSum = 0;
    int maxRowIdx = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        int currSum = 0;
        for (int j = 0; j < matrix[0].size(); j++)
        {
            currSum += matrix[i][j];
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
            maxRowIdx = i;
        }
        // maxSum = max(currSum,maxSum);
    }
    return {maxSum, maxRowIdx};
}

int returnColMaxSum(vector<vector<int>> matrix)
{
    int maxSum = 0;
    for (int i = 0; i < matrix[0].size(); i++)
    { // first traverse col then row
        int currSum = 0;
        for (int j = 0; j < matrix.size(); j++)
        {
            currSum += matrix[j][i];
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int returnDiagonalSumPD(vector<vector<int>> matrix)
{
    int sum = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        sum += matrix[i][i];
    }
    return sum;
}

int returnDiagonalSumSD(vector<vector<int>> matrix)
{
    int sum = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        sum += matrix[i][matrix.size()-1-i];
    }
    return sum;
}

int primaryDiagonalAndSecondryDiagonalSum(vector<vector<int>> matrix){
    int pdSum = 0;
    int sdSum = 0;
    int commonElem = 0;
    if(matrix.size() % 2 !=0){ // check if matrix is odd or even, if odd then continue
        commonElem = matrix[matrix.size()/2][matrix.size()/2];
    }
    for(int i=0;i<matrix.size();i++){
        pdSum += matrix[i][i];
        sdSum += matrix[i][matrix.size()-i-1];
    }
    // cout << matrix.size()/2 << endl;
    return pdSum + sdSum - commonElem;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3,1},
        {4, 5, 6,1},
        {7, 8, 9,1},
        {3, 6, 9,1},
    };
    // for(int i = 0;i<matrix.size();i++){
    //     for(int j = 0;j<matrix[0].size();j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // pair<int,int> ans = linearSearchMatrix(matrix,4);
    // cout << ans.first << " " << ans.second << " ";
    // pair<int,int> ans = returnRowMaxSum(matrix);
    // cout << ans.first << " " << ans.second << endl;
    // int ans = returnColMaxSum(matrix);
    // cout << ans << endl;

    vector<vector<int>> matrixx = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    // int ans = returnDiagonalSumSD(matrixx); // should be square matrix
    // cout << ans << endl;
    int ans = primaryDiagonalAndSecondryDiagonalSum(matrixx); // should be square matrix
    cout << ans << endl;
    return 0;
}