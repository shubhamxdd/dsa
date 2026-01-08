#include<bits/stdc++.h>
using namespace std;


void solveS(vector<vector<int>> &matrix, int row, int col, vector<vector<bool>> &visMatrix, vector<string> &validPaths, string currPath){
    int n = matrix.size();
    if(row < 0 || col < 0 || row>=n || col>=n || matrix[row][col] == 0 ||visMatrix[row][col] == true){
        return;
    }
    
    if(row==n-1 && col==n-1){
        validPaths.push_back(currPath);
        return;
    }

    // mark element as visited 
    visMatrix[row][col]=true;

    // call for all 4 directions
    // up
    solveS(matrix,row-1,col,visMatrix,validPaths,currPath+'U');
    // down
    solveS(matrix,row+1,col,visMatrix,validPaths,currPath+'D');
    // left
    solveS(matrix,row,col-1,visMatrix,validPaths,currPath+'L');
    // right
    solveS(matrix,row,col+1,visMatrix,validPaths,currPath+'R');

    // backtrack
    // mark visited as false
    visMatrix[row][col] = false;

}


vector<string> getPathOfMaze(vector<vector<int>> &matrix){
    int n = matrix.size();

    // store valid paths
    vector<string> validPaths;

    // visited matrix
    vector<vector<bool>> visMatrix(n,vector<bool>(n,false));
    
    string path = "";
    
    solveS(matrix,0,0,visMatrix,validPaths,path);
    return validPaths;
}


int main(){
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = getPathOfMaze(matrix);
    // print valid paths
    for(string path: paths){
        cout << path << endl;
    }
    cout << endl;


    return 0;
}