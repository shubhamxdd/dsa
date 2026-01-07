#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n){
    // check horizontal direction
    for(int j = 0;j<n;j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }

    // check vertical direction
    for(int i = 0;i<n;i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // check left diagonal
    for(int i = row,j = col;i>=0 && j>=0; i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    
    // check right diagonal
    for(int i = row,j = col;i>=0 && j<n; i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;

}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
    if(row == n){
        ans.push_back({board});
        return;
    }

    for(int j = 0;j<n;j++){
        if(isSafe(board,row,j,n)){
            board[row][j]= 'Q';
            nQueens(board,row+1,n,ans);
            board[row][j]= '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    // initialize variables
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    // call function
    nQueens(board,0,n,ans);


    return ans;
}

int main(){
    // print result
    vector<vector<string>> result = solveNQueens(4);
    for(auto &board : result){
        for(auto &row : board){
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}