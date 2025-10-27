#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void leftRotateaArrayByOne(vector<int> &arr)
{
    int temp = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[arr.size() - 1] = temp;
}

void leftRotateArrayByDPlaces(vector<int> &arr, int d)
{

    d = d % arr.size();
    // cout << d << endl;

    int temp[d];

    // move first d elem to temp array
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    /*
    // print temp arr for testing
    for(int iter: temp){
        cout << iter << " ";
    }
    */

    // shift elements
    for (int i = d; i < arr.size(); i++)
    {
        arr[i - d] = arr[i];
    }

    // put temp elements at end
    // int j = 0;
    // for(int i = arr.size()-d;i<arr.size();i++){
    //     arr[i]=temp[j];
    //     j++;
    // }
    for (int i = arr.size() - d; i < arr.size(); i++)
    {
        arr[i] = temp[i - (arr.size() - d)];
    }
}

void leftRoatateDPlaceOptimised(int arr[], int d, int n)
{
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

void rightRoatateDPlace(vector<int> &arr, int d, int n)
{
    d = d % n;
    d = arr.size() - d;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.begin() + n);
    reverse(arr.begin(), arr.begin() + n);
}

// brute
void moveZerosToEnd(vector<int> &arr)
{

    vector<int> temp;

    // store non zero elements in temp arr
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }

    for (int i = temp.size(); i < arr.size(); i++)
    {
        arr[i] = 0;
    }

    for (int iter : arr)
    {
        cout << iter << " ";
    }
}

void noveZerosToEndOptimal(vector<int> &arr)
{
    int j = -1;
    // find first index of zero and exit
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    // print arr
    for (int iter : arr)
    {
        cout << iter << " ";
    }
}

int linearSearch(vector<int> arr, int num)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

// brute
void unionSet(vector<int> arr1, vector<int> arr2)
{
    set<int> st;
    for (int i = 0; i < arr1.size(); i++)
    {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        st.insert(arr2[i]);
    }

    vector<int> unionArr;

    for (int iter : st)
    {
        unionArr.push_back(iter);
    }
    for (int iter : unionArr)
    {
        cout << iter << " ";
    }
}

vector<int> unionSetOptimal(vector<int> arr1, vector<int> arr2)
{
    int i = 0; // pointer for first array
    int j = 0; // pointer for second array

    vector<int> unionArr;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != arr2[j])
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (j < arr2.size())
    {
        if (unionArr.size() == 0 || unionArr.back() != arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    while (i < arr1.size())
    {
        if (unionArr.size() == 0 || unionArr.back() != arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    return unionArr;
}

vector<int> intersectionBrute(vector<int> arr1, vector<int> arr2)
{
    vector<int> resultArr;

    int visited[arr2.size()] = {0};

    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr1[i] == arr2[j] && visited[j] == 0)
            {
                resultArr.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }

    return resultArr;
}

vector<int> intersectionOptimal(vector<int> arr1, vector<int> arr2)
{
    int i = 0;
    int j = 0;
    vector<int> resultArr;

    while (i < arr1.size() && arr2.size())
    {
        if (arr1[i] < arr2[j])
        {        // that is not common element
            i++; // so move to next elem
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            resultArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return resultArr;
}

// brute
int longestSubarrayOfSumK(vector<int> arr, int target)
{
    int longestLength = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if(sum == target){
                longestLength = max(longestLength,j-i+1);
            }
        }
    }
    return longestLength;
}

int main()
{
    /*
    vector <int> arr = {1,2,3,4,5};
    leftRotateaArrayByOne(arr);
    for(int iter:arr){
        cout <<  iter << " ";
        }
        */
    /*
    vector <int> arr[] = {1,2,3,4,5,6,7};
    leftRotateArrayByDPlaces(arr,3);
    for(int iter:arr){
        cout <<  iter << " ";
    }
    */

    /*
    vector<int> arr = {1, 2, 3, 4, 5};
    // leftRoatateDPlaceOptimised(arr,3,5);
    rightRoatateDPlace(arr, 3, 5);
    for (int iter : arr)
    {
        cout << iter << " ";
    }
    */

    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    // moveZerosToEnd(arr);
    // noveZerosToEndOptimal(arr);
    // cout << linearSearch(arr,4) << endl;

    /*
        vector<int> arr1 = {1, 1, 2, 3, 4, 5};
        vector<int> arr2 = {2, 3, 4, 4, 5, 6};
        // unionSet(arr1,arr2);
        vector<int> soln = unionSetOptimal(arr2, arr1);

        for (int iter : soln)
        {
            cout << iter << " ";
            }
            */
    vector<int> arr1 = {1, 1, 2, 3, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5};

    // vector<int> intersectionArr = intersectionBrute(arr1, arr2);
    // vector<int> intersectionArr = intersectionOptimal(arr1, arr2);

    // for (int iter : intersectionArr)
    // {
    //     cout << iter << " ";
    // }

    cout << longestSubarrayOfSumK(arr1, 3);

    return 0;
}