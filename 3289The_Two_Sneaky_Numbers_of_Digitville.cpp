#include <bits/stdc++.h>
using namespace std;

vector<int> getSneakyNumbersMap(vector<int> &nums){
    map<int,int> mp;
    vector<int> answer = {};

    for(int i:nums){
        if(mp[i]>0) answer.push_back(nums[i]);
        else mp[i]++;
    }
    return answer;
}

vector<int> getSneakyNumbers(vector<int> &nums){
    int n = nums.size();
    vector<int> answer = {};

    for(int i = 0;i<n;i++){
        int count = 0;
        // count number of times a number comes
        for(int j = 0;j<n;j++){
            if(nums[i] == nums[j]) count++;
        }
        if(count == 2){
            bool isPresent = false;
            for(int k = 0;k<answer.size();k++){
                if(answer[k] == nums[i]){
                    isPresent = true;
                }
            }
            if(!isPresent){
                answer.push_back(nums[i]);
            }
        }
    }
    return answer;
}


int main(){
    vector<int> nums = {0,1,1,0};
    // vector<int> ans = getSneakyNumbersMap(nums);
    vector<int> ans = getSneakyNumbers(nums);
    for(int iter:ans){
        cout << iter << " ";
    }
    return 0;
}