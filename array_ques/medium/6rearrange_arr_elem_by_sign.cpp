#include <bits/stdc++.h>
using namespace std;



vector<int> brute(vector<int> &arr){
    vector<int> positive;
    vector<int> negative;

    for(int i = 0;i<arr.size();i++){
        if(arr[i]>0) positive.push_back(arr[i]);
        else negative.push_back(arr[i]);
    }

    for(int i = 0;i<arr.size()/2;i++){
        arr[2*i] = positive[i];
        arr[2*i+1] = negative[i];
    }
    return arr;

}

vector<int> better(vector<int> &arr){
    vector<int> ans(arr.size(),0);

    int positiveIdx = 0;
    int negativeIdx = 1;

    for(int i = 0;i<arr.size();i++){
        if(arr[i]<0){
            ans[negativeIdx] = arr[i];
            negativeIdx +=2;
        } else{
            ans[positiveIdx] = arr[i];
            positiveIdx +=2;

        }
    }

    return ans;
}

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    vector<int> answer = brute(arr);
    // vector<int> answer =better(arr);
    for(int iter:answer) cout << iter << " ";
    return 0;
}