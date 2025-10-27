#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumBrute(vector<int> arr)
{
    int maximum = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
                maximum = max(sum, maximum);
            }
        }
    }
    return maximum;
}

int maxSubarraySumBetter(vector<int> arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int maxSubarraySumBestOptimal(vector<int> arr){
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++){
        sum+=arr[i];

        if(sum>maxi){
            maxi = sum;
        }

        if(sum<0){
            sum = 0;

        }
    }
    return maxi;
    
}

int maxSubarraySumBestOptimalV2(vector<int> arr){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0;i<arr.size();i++){
        sum = max(arr[i],sum+arr[i]);
        maxi = max(sum,maxi);
    }
    return maxi;
}


int maxSubarraySumPrintSubarrayBestOptimal(vector<int> arr){
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;
    int ansStart = 0;
    int ansEnd = 0;
    for (int i = 0; i < arr.size(); i++){
        sum+=arr[i];

        // if(sum==0){
        //     start = i+1;
        // }
        
        
        if(sum>maxi){
            maxi = sum;
            ansStart=start;
            ansEnd = i;
        }
        
        
        if(sum<0){
            sum = 0;
            start = i+1;

        }
    }
    for(int i = ansStart;i<=ansEnd;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // cout << ansStart<<endl;
    // cout << ansEnd<<endl;
    return maxi;
    
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    // cout << maxSubarraySumBrute(arr) << endl;
    // cout << maxSubarraySumBetter(arr) << endl;
    // cout << maxSubarraySumBestOptimal(arr) << endl;
    // cout << maxSubarraySumBestOptimalV2(arr) << endl;
    cout << maxSubarraySumPrintSubarrayBestOptimal(arr) << endl;
    return 0;
}