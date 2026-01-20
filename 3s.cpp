#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumBrute(vector<int>& nums) {
    // sort(nums.begin(), nums.end());
    set<vector<int>> st;
    vector<vector<int>> res = {};
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] + nums[k] == 0){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(),triplet.end());
                    if(st.find(triplet) == st.end()){
                        st.insert(triplet);
                        res.push_back(triplet);
                    }
                }
            }
        }
    }
    return res;
}


vector<vector<int>> threeSumBetter(vector<int> &nums){
    set<vector<int>> ans;
    for(int i = 0;i<nums.size();i++){
        set<int> s;
        for(int j = i+1;j<nums.size();j++){
            // a+b+c=0
            // c = -(a+b)
            int c = -(nums[i] + nums[j]);
            // find c in set, if exist found triplet, if not continue
            if(s.find(c) != s.end()){
                // c found
                vector<int> triplet = {nums[i],nums[j],c};
                sort(triplet.begin(),triplet.end());
                ans.insert(triplet);
            }
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> anss(ans.begin(),ans.end());
    return anss;
}


int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    // vector<vector<int>> result = threeSumBrute(arr);
    vector<vector<int>> result = threeSumBetter(arr);
    for(auto vec : result){
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}