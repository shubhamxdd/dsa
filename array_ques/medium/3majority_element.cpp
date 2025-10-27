#include <bits/stdc++.h>
using namespace std;

int majorityElementBrute(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > (arr.size() / 2))
        {
            return arr[i];
        }
    }
    return -1; // if not found
}

int majorityElementBetter(vector<int> arr)
{
    map<int, int> hashmap;
    for (int i = 0; i < arr.size(); i++)
    {
        hashmap[arr[i]]++;
    }
    for (auto iter : hashmap)
    {
        if (iter.second > (arr.size() - 1) / 2)
        {
            return iter.first;
        }
    }
    return -1;
}

int majorityElementBestOptimal(vector<int> arr)
{
    int count = 0;
    int elem;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            elem = arr[i];
        }
        else if (arr[i] == elem)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int count1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == elem)
        {
            count1++;
        }
    }
    if (count1 > arr.size() / 2)
        return elem;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
    // cout << majorityElementBrute(arr) << endl;
    // cout << majorityElementBetter(arr) << endl;
    cout << majorityElementBrute(arr) << endl;

    return 0;
}