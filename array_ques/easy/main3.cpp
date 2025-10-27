#include <bits/stdc++.h>

using namespace std;

int missingNumberBrute(vector<int> arr, int num)
{
    for (int i = 1; i <= arr.size(); i++)
    { // runs from 1 to num
        bool found = false;
        for (int j = 0; j < arr.size(); j++)
        { // runs from 0 to size of array for index
            if (arr[j] == i)
            {
                found = true; // if element is found return true
                break;
            }
        }
        if (!found)
        {
            return i;
        }
    }
}

// sum
int missingNumberOptimal(vector<int> arr, int n)
{
    // sum of elements from 1 to arr.size()
    // int sum = ((arr.size()+1) * (arr.size() + 2)) / 2;
    int sum = (n * (n + 1)) / 2;

    // sum of elements in array
    int arrSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        arrSum += arr[i];
    }

    int missingNumber = sum - arrSum;

    return missingNumber;
}

int maximumConsequtiveOnes(vector<int> arr)
{
    int count = 0;
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
            maxi = max(count, maxi);
        }
        else
        {
            count = 0;
        }
    }
    return maxi;
}

int numberOnceOtherTwice(vector<int> arr)
{
    // find max element
    int maximum = arr[0];
    for (int i = 0; i < arr.size(); i++){
        maximum = max(maximum, arr[i]);
    }
    int hashArr[maximum]={0};
    
    
    for(int i = 0;i<arr.size();i++){
        hashArr[arr[i]]++;
    }

    for(int i = 1;i<maximum;i++){
        if(hashArr[i] == 1){
            return i;
        }
    }
    return -1;
}


int numberOnceOtherTwiceOptimal(vector<int> arr){
    int xor1 = 0;

    for(int i = 0;i<arr.size();i++){
        xor1 = xor1 ^ arr[i];
    }

    return xor1;


}
int main()
{
    // vector<int> arr = {1,2,3,5};
    // vector<int> arr = {5,1,2,3};
    // cout << missingNumberBrute(arr,5) << endl;
    // cout << missingNumberOptimal(arr,5) << endl;

    /*
    vector<int> conseqArr = {1,0,1,1,1,1,0,1,0,1,1};
    cout << maximumConsequtiveOnes(conseqArr) << endl;
    */
    vector<int> twArr = {1, 1, 2,2, 3, 3, 4, 4,9};
    // cout << numberOnceOtherTwice(twArr) << endl;
    cout << numberOnceOtherTwiceOptimal(twArr) << endl;

    return 0;
}