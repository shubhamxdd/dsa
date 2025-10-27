// print a number

#include <bits/stdc++.h>
using namespace std;

void printDigitsInReverse(int num)
{
    while (num > 0)
    {
        int lastDigit = num % 10;
        cout << lastDigit << endl;
        num = num / 10;
    }
}

void countDigits(int num)
{
    int digits = 0;
    while (num > 0)
    {
        num = num / 10;
        digits++;
    }
    cout << digits << endl;
    // time complexity => O(log10 n) 10 because dividing by 10
    // if num was divided by 5 it should be O(log5 n)
}

void reverseNumber(int num)
{
    int reversed = 0;
    while (num > 0)
    {
        int lastDigit = num % 10;
        num = num / 10;
        reversed = (reversed * 10) + lastDigit;
    }
    cout << reversed << endl;
}

void checkPalindrome(int num)
{
    int num_dup = num;
    int reversed = 0;
    while (num > 0)
    {
        int lastDigit = num % 10;
        num = num / 10;
        reversed = (reversed * 10) + lastDigit;
    }

    if (reversed == num_dup)
    {
        cout << "Palindrome number!!";
    }
    else
    {
        cout << "not a palindrome number!!";
    }
}

void checkArmstrongNumber(int num)
{
    int numDup = num;
    int sum = 0;
    while (num > 0)
    {
        int lastDigit = num % 10;
        sum += (lastDigit * lastDigit * lastDigit);
        num = num / 10;
    }
    if (sum == numDup)
    {
        cout << "is armstrong number";
    }
    else
    {
        cout << "is not armstrong number";
    }
}

void printAllDivisors(int num)
{
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << endl;
        }
    }
}

void checkForPrine(int num)
{
    int count = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
        // if(count > 2) break;
    }

    if (count <= 2)
    {
        cout << "Prime hai" << endl;
    }
    else
        cout << "Not a prime" << endl;
}

void HCF(int num1, int num2)
{
    // run loop from 1 to num2
    // divide both numbers and note common divisor and print higest common number

    int myHCF;

    // cout << min(num1, num2) << endl;

    for (int i = 1; i < min(num1,num2); i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            myHCF = i;
        }
    }

    cout << "GCD is: " << myHCF << endl;
}

int main()
{
    // printDigitsInReverse(213);
    // countDigits(234);
    // reverseNumber(134);
    // checkPalindrome(121);
    // checkArmstrongNumber(153);
    // printAllDivisors(36);
    /*
    checkForPrine(71);
    checkForPrine(73);
    checkForPrine(74);
    checkForPrine(81);
    */
    HCF(40, 12);

    return 0;
}