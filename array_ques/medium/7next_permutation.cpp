#include <bits/stdc++.h>
using namespace std;

vector<int> better(vector<int> &arr){
    next_permutation(arr.begin(),arr.end());
    return arr;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<int> ans = better(arr);

    for(int iter:arr){
        cout << iter << " ";
    }
    
    return 0;
}