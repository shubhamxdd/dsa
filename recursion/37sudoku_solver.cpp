#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board,int row, int col, int digit){
    // check horizontally
    for(int j = 0;j<9;j++){
        if(board[row][j] == digit){
            return false;
        }
    }
    
    // check vertically
    for(int i = 0;i<9;i++){
        if(board[i][col] == digit){
            return false;
        }
    }
    // check in grid

    int startRow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i = startRow;i<=startRow+2;i++){
        for(int j = startCol;j<=startRow+2;j++){
            if(board[i][j] == digit){
                return false;
            }
        }
    }

    return true;
}

bool solveS(vector<vector<char>> &board,int row, int col){
    // base case
    if(row == 9){
        return true;
    }
    // update nextrow, nextcol
    int nextRow = row;
    int nextCol = col+1;
    if(nextCol == 9){
        nextRow = row+1;
        nextCol = 0;
    }
    // check if element is placed or not
    if(board[row][col]!='.'){
        // if placed, place next element
        return solveS(board,nextRow,nextCol);
    }
    // place element
    for(char digit = '1';digit<'9';digit++){
        if(isSafe(board,row,col,digit)){
            board[row][col] = digit;
            if(solveS(board,nextRow,nextCol)){
                return true;
            }
        board[row][col]='.';
        }
    }
    return false;
}

int main(){
    return 0;
}