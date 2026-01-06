#include<bits/stdc++.h>
using namespace std;

void getPermutations(vector<int> &arr,int index, vector<vector<int>> &ansArr){
    if(index==arr.size()){
        ansArr.push_back({arr});
        return;
    }
    for(int i = index;i<arr.size();i++){
        swap(arr[i],arr[index]);
        getPermutations(arr,index+1,ansArr);
        swap(arr[i],arr[index]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ansArr;
    getPermutations(nums,0,ansArr);
    return ansArr;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> result = permute(arr);
    for(auto vec : result){
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}