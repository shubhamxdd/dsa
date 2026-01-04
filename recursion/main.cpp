#include <bits/stdc++.h>
using namespace std;

void printNums(int n){
    if(n==1) {
        cout << 1 << endl;
        return;
    }
    cout << n << endl;
    printNums(n-1);
}

int factorial(int n){
    if(n==0) return 1;
    return n * factorial(n-1);
}

int summ(int n){
    if(n==1) return 1;
    return n+summ(n-1);
}

int summ2(int currSum, int n){
    if(n==0) return currSum;
    return summ2(currSum+n, n-1);
}

int main(){
    // printNums(10);
    // cout << factorial(4);
    // cout << summ(4);
    cout << summ2(0,4);
    return 0;
}