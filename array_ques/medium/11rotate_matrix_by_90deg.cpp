#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(vector<vector<int>> &matrix)
{ // square matrix
    int n = matrix.size();

    vector<vector<int>> ansMatrix(4, vector<int>(4,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ansMatrix[j][n-i-1] = matrix[i][j];
        }
    }

    return ansMatrix;
}

void swapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


void reverseArray(vector<int> & arr){
    int left = 0;
    int right = arr.size() - 1;

    while(left<right){
        swapInt(arr[left], arr[right]);
        left++;
        right--;
    }
}


void better(vector<vector<int>> &matrix){
    int n = matrix.size();
    
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            swap(matrix[i][j], matrix[j][i]); // swap elements across diagonal
        }
    }

    for (int i = 0; i < n; i++){
        // reverse(matrix[i].begin(),matrix[i].end()); // revrse each row
        reverseArray(matrix[i]); 
    }
    

}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    // vector<vector<int>> ans = brute(matrix);

    better(matrix);

for(int i = 0;i<matrix.size();i++){
    for(int j = 0;j<matrix.size();j++){
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
    return 0;
}