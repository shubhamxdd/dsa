#include <bits/stdc++.h>
using namespace std;

int largestElemInArray(int arr[], int n)
{
    int largestIdx = 0; // assume largest elem is 1

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[largestIdx])
        {
            largestIdx = i;
        }
    }
    return arr[largestIdx];
}

int secondLargestElementInArray(vector<int> arr)
{
    // find largest elem
    int largestIdx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > arr[largestIdx])
        {
            largestIdx = i;
        }
    }

    int largestElem = arr[largestIdx];

    int secondLargestElem = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > secondLargestElem && arr[i] != largestElem)
        {
            secondLargestElem = arr[i];
        }
    }
    return secondLargestElem;
}

/*
int secondLargest(vector<int> arr){
    // find largest
    int largestIdx = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>arr[largestIdx]){
            largestIdx = i;
        }
    }
    int secondLargest=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>secondLargest && arr[i]!=arr[largestIdx]){
            secondLargest = arr[i];
        }
    }

    return secondLargest;

}
int secondSmallest(vector<int> arr){
    // find smallest elem
    int smallestElemIdx=0;
    for(int i=0;i<arr.size();i++){
        if(arr[smallestElemIdx]>arr[i]){
            smallestElemIdx = i;
        }
    }
    int smallestNum = arr[smallestElemIdx];

    // second smallest

    int secondSmallest = INT_MAX;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<secondSmallest && arr[i]!=smallestNum){
            secondSmallest=arr[i];
        }
    }
    return secondSmallest;

}
*/

int secondLargest(vector<int> &arr)
{
    int largest = arr[0];
    int secondLargest = -1; // assuming there are no negative elements in arr

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > largest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int secondSmallest(vector<int> &arr)
{
    int smallest = arr[0];
    int secondSmallest = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] != secondSmallest)
        {
            secondSmallest = arr[i];
        }
    }

    return secondSmallest;
}

// second order element
void secondLargestAndSmallestElementInArray(vector<int> arr)
{
    int sLargest = secondLargest(arr);
    int sSmallest = secondSmallest(arr);

    cout << "Second Largest element: " << sLargest << endl;
    cout << "Second Smallest element: " << sSmallest << endl;
}

bool isArraySorted(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
            return false;
    }
    return true;
}

int removeDuplicateFromSortedArray(vector<int> &arr)
{
    int i = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    return i + 1; // return number of unique elements
}

int main()
{
    // int arr[6] = {3,2,1,5,2};
    // int n = 5;
    // cout << largestElemInArray(arr,n) << endl;
    // vector<int> arr = {3,2,1,5,2};
    // vector<int> arr = {6,4,1,5,8,7,8,90,89};
    // cout << secondLargestElementInArray(arr) << endl;
    // vector<int> arr = {3, 2, 1, 5, 2};
    // secondLargestAndSmallestElementInArray(arr);

    /*
    vector<int> arr = {3, 2, 1, 5, 2};
    vector<int> sArr = {1, 2, 3, 4, 5, 6};

    if (isArraySorted(arr))
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not Sorted" << endl;
    }
    if (isArraySorted(sArr))
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not Sorted" << endl;
    }
    */

    vector<int> arrWithDupElem = {1, 1, 2, 2, 3, 3};

    cout << removeDuplicateFromSortedArray(arrWithDupElem) << endl;

    return 0;
}