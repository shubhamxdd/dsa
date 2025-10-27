#include <iostream>

using namespace std;

void pattern1(int size)
{
    /*
    ****
    ****
    ****
    ****
    */
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(int size)
{
    /*
     *
     **
     ***
     ****
     *****
     */

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern3(int size)
{
    /*
     1
     12
     123
     1234
     12345
     */

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

void pattern4(int size)
{
    /*
     1
     22
     333
     4444
     555555
     */

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << i;
        }
        cout << i << endl;
    }
}

void pattern5(int size)
{
    /*
     *****
     ****
     ***
     **
     *
     */

    /*
    method 1
    for (int i = 1; i <= size; i++)
    {
       for (int j = size; j >= i; j--)
       {
           // cout << "* ";
           cout << "Value of i: " << i << " & value of j: " << j << endl;
           }

           cout << endl;
           }
           */

    for (int i = size; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            // cout << "Value of i: " << i << " & value of j: " << j << endl;
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int size)
{
    /*
     12345
     1234
     123
     12
     1
     */

    /*
    method 1
    for (int i = 1; i <= size; i++)
    {
       for (int j = size; j >= i; j--)
       {
           // cout << "* ";
           cout << "Value of i: " << i << " & value of j: " << j << endl;
           }

           cout << endl;
           }
           */

    for (int i = size; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            // cout << "Value of i: " << i << " & value of j: " << j << endl;
            cout << j;
        }
        cout << endl;
    }
}

void pattern7(int size)
{
    /*
    triangle
    *
   ***
  *****
 *******
*********
     */

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < size - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern8(int size)
{
    /*
    reversed triangle
     *********
      *******
       *****
        ***
         *
     */

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (2 * size) - (2 * i + 1); j++)
        {
            cout << "*";
        }
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern9(int size)
{
    /*
    *
   ***
  *****
 *******
*********
*********
 *******
  *****
   ***
    *

    */
    pattern7(size);
    pattern8(size);
}

void pattern10(int size)
{

    /*
     *
     * *
     * * *
     * * * *
     * * * * *
     * * *
     * *
     *
     */

    // Ascending part (1 to size stars)
    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Descending part (size-1 to 1 stars)
    for (int i = size - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern11(int size)
{
    /*
    1
    01
    101
    0101
    10101
    */

    int start;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;

        for (int j = 0; j <= i; j++)
        {
            cout << start;
            if (start == 0)
                start = 1;
            else if (start == 1)
                start = 0;
        }
        cout << endl;
    }
}

int main()
{
    // pattern1(4);
    // pattern2(6);
    // pattern3(5);
    // pattern4(7);
    // pattern5(5);
    // pattern6(5);
    // pattern7(5);
    // pattern8(5);
    // pattern9(5);
    // pattern10(3);
    // pattern11(8);

    return 0;
}