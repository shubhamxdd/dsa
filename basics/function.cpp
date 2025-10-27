#include <bits/stdc++.h>

using namespace std;

/*
void printName(string name)
{
    cout << name << endl;
}
*/

int twoSum(int a, int b)
{
    return a + b;
}

int addFiveToNumber(int number)
{
    return number += 5;
}
// attact & to pass by reference
int addFiveToNumberByReference(int &number)
{
    return number += 5;
}

int main()
{
    /*
    int num1 = 4;
    // cout << "Enter first number: ";
    // cin >> num1;

    // pass by value as original value is still unaffected // original value doesnt change
    cout << num1 << " + " << " 5 " << " = " << addFiveToNumber(num1) << endl; // output 9

    cout << "Original number is: " << num1; // output 4
    */
    // -----------------------------------------------

    // Pass by reference , original value changes
    int num2; // input 4
    cout << "Enter second number: ";
    cin >> num2;
    int ans = addFiveToNumberByReference(num2);
    cout << num2 << " + " << " 5 " << " = " << ans << endl; // output 9
    cout << "Original number is: " << num2; // output 9
    /*
     string name;
     cout << "Enter your name: ";
     cin >> name;
     printName(name);
     */
    return 0;
}