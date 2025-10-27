#include <bits/stdc++.h>
using namespace std;

int stockBuySellBrute(vector<int> arr){
    int minVal = arr[0];
    int profit = 0;
    int cost = 0;
    for(int i = 1;i<arr.size();i++){
        cost = arr[i] - minVal;

        profit = max(cost,profit);

        minVal = min(minVal,arr[i]);
    }
    return profit;
}

int main(){
    vector<int> arr = {7,1,5,3,6,4};
    cout << stockBuySellBrute(arr) << endl;
    return 0;
}