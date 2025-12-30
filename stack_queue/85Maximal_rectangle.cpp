#include <bits/stdc++.h>
using namespace std;

int largestAreaBetter(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n); // right
    vector<int> pse(n); // left
    stack<int> st;

    // nse
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    // pse
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int area = arr[i] * (nse[i] - pse[i] - 1); // height is arr[i] width is nse[i]-pse[i]-1
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int maxArea = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> prefixSumMatrix(rows, vector<int>(cols, 0));

    // compute sum from top to down
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] == '0'){
                prefixSumMatrix[i][j] = 0;
            }else {
                prefixSumMatrix[i][j] = (i==0)?1:prefixSumMatrix[i-1][j]+1 ;
            }
        }
    }
    // now iterate over each row and find its max area

    for (int i = 0; i < rows; i++)
    {
        maxArea = max(largestAreaBetter(prefixSumMatrix[i]), maxArea);
    }
    return maxArea;
}

int main()
{
    vector<vector<char>> arr = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(arr);
    return 0;
}