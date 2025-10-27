#include <bits/stdc++.h>
using namespace std;

// brute
int square_root(int num){
    int ans = 1;
    for(int i = 0;i<=num;i++){
        if(num>=i*i){
            ans = i;
        }else{
            break;
        }
    }
    return ans;
}

int main(){
    cout << square_root(15);
    return 0;
}