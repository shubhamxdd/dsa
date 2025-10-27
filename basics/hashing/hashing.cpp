#include <bits/stdc++.h>

using namespace std;


// inputs => size, array, number of queries, queries like find frequency of 1 2,3 etc..
int main(){
    int n = 5;
    // cin >> n; // size

    int arr[n] = {1,2,3,4,2};
    // for(int i=0; i<n;i++){
    //     cin >> arr[i]; // take input array from user
    // }


    // precompute
    int hash[13]={0}; // 12 elements max 

    for (int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    } // hasharray ready
    

    int q = 5;
    // cin >> q;// number of queries
    while (q--){
        int number;
        cout << "Enter number you want to find frequency of: ";
        cin >> number; // number of each query

        // fetch answer here

        cout <<"Answer is: " << hash[number]<< endl; // number of time a number appears
    }

    return 0;
    
}
