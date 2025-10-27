#include <bits/stdc++.h>
using namespace std;

/*
// infinite recursion
void func(){
    cout <<"Hi"<<endl;
    func();
}
*/

/*
// finite recursion
int myCount = 0;
void func(){
    cout << myCount << endl;
    if(myCount == 10) return; // base condition
    myCount++;
    func();
}
*/

/*
void printNTimes(int times){
    if(times == 0) return; // print 5 times
    cout << "Shubham" << endl;
    printNTimes(times-1);
}
*/

// i => current index, n => total times to print
void printNTimes(int i, int n)
{
    if (i > n)
        return;
    cout << "Shubham!" << endl;
    printNTimes(i + 1, n);
}

void printOneToNLinearly(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    printOneToNLinearly(i + 1, n);
}

void printNToOneLinearly(int i, int n)
{
    if (i < n)
        return;
    cout << i << endl;
    printNToOneLinearly(i - 1, n);
}

void printOneToNBacktracking(int i, int n)
{
    // print one to n without using +1
    if (i < 1)
        return;
    printOneToNBacktracking(i - 1, n);
    cout << i << endl;

    // if function call is above cout then it prints in 1,2,3.....
    // if function call is below cout then it prints in 10,9,8....
}

void sumRecursionParameter(int i, int sum)
{
    // parameterized way
    if (i < 1)
    {
        cout << sum << endl;
        return;
    }
    sumRecursionParameter(i - 1, sum + i);
}

int sumRecursionFunctional(int n)
{
    if (n == 0)
    {
        // sum will be zero
        return 0;
    }
    return n + sumRecursionFunctional(n - 1);
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

void reverseArray(int arr[], int i, int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverseArray(arr, i + 1, n);
}

void revArr2P(int l, int r, int arr[])
{
    // l and r are 2 pointer that are left and right
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    revArr2P(l + 1, r - 1, arr);
}

bool palindrome(int i, string s)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    return palindrome(i + 1, s);
}

int nthFibonacciNUmber(int n)
{
    if (n <= 1)
        return n;

    return nthFibonacciNUmber(n - 1) + nthFibonacciNUmber(n - 2);
}

int main()
{
    // func();
    // printNTimes(1,5);
    // printOneToNLinearly(1,10);
    // printNToOneLinearly(10,1);
    // printOneToNBacktracking(3,3);
    // sumRecursionParameter(3,0);
    // cout << sumRecursionFunctional(3) << endl;
    // cout << factorial(4)<<endl;
    /*
    int arr[5] = {1, 2, 3, 4, 5};
    reverseArray(arr, 0, 5);
    revArr2P(0,4,arr);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    */
    /*
    cout << palindrome(0, "madam") << endl;
    cout << palindrome(0, "madsm") << endl;
    cout << palindrome(0, "racecar") << endl;
    cout << palindrome(0, "racetar") << endl;
    */

    cout << nthFibonacciNUmber(4) << endl;

    return 0;
}