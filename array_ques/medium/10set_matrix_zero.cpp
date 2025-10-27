#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix, int i)
{
    for (int j = 0; j < matrix[0].size(); j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = INT_MIN;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int j)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = INT_MIN;
        }
    }
}

void brute(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, i);
                markCol(matrix, j);
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == INT_MIN)
            {
                matrix[i][j] = 0;
            }
        }
    }
}


void better(vector<vector<int>> &matrix){
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    vector<int> row(rowSize,0);
    vector<int> col(colSize,0);

    // int row[rowSize]={0};
    // int col[colSize]={0};

    for(int i = 0;i<rowSize;i++){
        for(int j = 0;j<colSize;j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0;i<rowSize;i++){
        for(int j = 0;j<colSize;j++){
            if(row[i] || col[j]){
                matrix[i][j]=0;
            }
        }
    }    
}



int main()
{

    vector<vector<int>> matrix = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    // brute(matrix);
    better(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}