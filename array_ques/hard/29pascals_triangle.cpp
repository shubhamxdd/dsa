#include <bits/stdc++.h>
using namespace std;

int factorial(int num){
    if(num == 1) return 1;
    return num * factorial(num-1);
}

//type 1
// find elememt at given row and col
// BRUTE
int elem(int r, int c){
    // find r - 1
    //           C
    //             n-1
    int sol = factorial(r-1) / (factorial(r-1-c+1) * factorial(c-1));
    return sol;
}

// better
int elem2(int n, int r){
    int result = 1;
    for(int i = 0;i<r;i++){
        result = result * (n-1);
        result = result/(i+1);
    }
    return result;
}

int calculateNCR(int n, int r){
    int result = 1;
    for(int i = 0;i<r;i++){
        result = result * (n-1);
    }
    return result;
}

// type 2
// print any row of pascal triangle
// void printRow(int r){
//     for(int i = 1;i<=r;i++){
//         cout << calculateNCR(r-1,i-1) << " ";
//     }
// }

void printnthRow(int row){
    int ans = 1; 
    cout << ans << " ";
    for(int i = 1;i<row;i++){
        ans = ans * (row-1);
        ans = ans/i;
        cout << ans << " ";
    }
}

int main(){
    // cout << factorial(5) << endl;
    // cout << elem2(3,2) << endl;
    // cout << elem2(10,3) << endl;
    // printRow(3);
    printnthRow(4);
    return 0;
}