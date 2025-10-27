#include <bits/stdc++.h>
using namespace std;

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

int main()
{

    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};

    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}