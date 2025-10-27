#include <iostream>

using namespace std;

int main()
{
    /*
    // mark below 25 = F
    // mark bw 25 to 44 = E
    // mark bw 45 to 49 = D
    // mark bw 50 to 59 = C
    // mark bw 60 to 79 = B
    // mark bw 80 to 100 = A

    int marks=58;
    // cout << "Enter marks to get coresponding grade: ";
    // cin >> marks;

    if(marks<25){
        cout << "F";
    } else if (marks <=44 ){
        cout << "E";
    } else if (marks <=49 ){
        cout << "D";
    } else if (marks <=59 ){
        cout << "C";
    } else if (marks <=79){
        cout << "B";
    }else if(marks <= 100){
        cout << "A";
    }
    */

    /*
    int age =55;
    // cout << "Enter age: ";
    // cin >> age;


    if(age<18){
        cout << "Not eligible";
    }else if(age<=57){
        cout <<"Eligible";
        if(age>=55){
            cout <<", but retirement soon";

        }
    } else if (age > 57){
        cout <<"retirement time";

    }
    */

    // Switch case

    int day = 4;

    switch (day)
    {
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;

    default:
        cout << "FRI/SAT";
        break;
    }

    return 0;
}