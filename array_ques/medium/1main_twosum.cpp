#include <bits/stdc++.h>
using namespace std;

pair<int, int> twoSumBrute(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<int> twoSumBetter(vector<int> arr, int target)
{
    map<int, int> hashmap;
    for (int i = 0; i < arr.size(); i++)
    {
        int elem = arr[i];
        int required = target - arr[i];
        if (hashmap.find(required) != hashmap.end())
        {
            // return "YES";
            return {hashmap[required], i};
        }
        hashmap[elem] = i;
    }
    return {-1, -1};
}

int partitionFunc(vector<int> &arr, int low, int high)
{
    int pivotElem = arr[low];
    int i = low;  // left pointer
    int j = high; // right pointer

    while (i < j)
    {
        // find first small elem than pivot
        while (arr[i] <= pivotElem && i <= high - 1)
        {
            i++;
        }

        // find first large elem than pivot
        while (arr[j] > pivotElem && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // then only do it
        int partitionIndex = partitionFunc(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

string twoSumYesNoOptimal(vector<int> &arr, int target)
{
    // sort array
    quickSort(arr, 0, arr.size() - 1);
    // sort(arr.begin(),arr.end());
    // for(int iter:arr){
    //     cout << iter << " ";
    // }

    int left = arr[0];
    int right = arr[arr.size() - 1];

    while (left < right)
    {

        if (arr[left] + arr[right] < target)
        {
            left++;
        }
        else if (arr[left] + arr[right] > target)
        {
            right++;
        }else {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    vector<int> arr = {1, 3, 2, 5, 6};
    pair<int, int> ans = twoSumBrute(arr, 7);
    // cout << ans.first << " " << ans.second << endl;

    vector<int> sol = twoSumBetter(arr, 5);

    // for (int iter : sol)
    // {
    //     cout << iter << " ";
    // }

    cout << twoSumYesNoOptimal(arr,5) << endl;
    // twoSumYesNoOptimal(arr, 5);

    return 0;
}