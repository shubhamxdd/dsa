#include <bits/stdc++.h>

using namespace std;

int doSomething(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] += 100;
    }
    return 0;
}

int main()
{
    /*
    int arr[3][5]={
        {1,2,3,4,5},
        {6,7,8,9,1},
        {22,5,1,6,8}
    };

    // cout << arr;

    for(int i=0;i<3;i++){
        // cout << i;
        for(int j=0;j<5;j++){
            // cout << j;
            cout <<"Element at i [" << i << "], j [" << j << "] is " << arr[i][j]<<endl;
        }
    }
    */

    /*

    string s = "shubham";
    int len = s.size();

    s[1] = 'k';

    cout << s << endl;
    cout << "length is: " << len;
    */

    /*
    int i=0;

    while (i<5)
    {
        cout << "Shubham "<< i << endl;
            i++;
        }
    */

    /*

    int i = 0;

    do
    {
        cout << "Shubham " << i << endl;
        i++;
    } while (i < 4);

    */

    int arr[5] = {22, 33, 44, 11, 66};
    int lengthArr = 5;

    for (int i = 0; i < lengthArr; i++)
    {
        cout << arr[i] << endl;
    }

    doSomething(arr, lengthArr);

    for (int i = 0; i < lengthArr; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}