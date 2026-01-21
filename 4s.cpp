#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSumBrute(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                for(int l = k+1;l<n;l++){
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
                    if(sum == target){
                        // push in set
                        vector<int> quad = {nums[i],nums[j],nums[k],nums[l]};
                        sort(quad.begin(),quad.end());
                        if(st.find(quad) == st.end()){
                            st.insert(quad);
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> fourSumBetter(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            set<long long> hashset;
            for(int k = j+1;k<n;k++){
                // a+b+c+d = target => d = target-(a+b+c)
                long long sum = ((long long)nums[i]+(long long)nums[j]+(long long)nums[k]);
                long long d = (long long)target-sum;

                if(hashset.find(d) != hashset.end()){
                    // found a possible answer
                    vector<int> quad = {nums[i],nums[j],nums[k],(int)d};
                    sort(quad.begin(),quad.end());
                    st.insert(quad);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}



int main(){
    vector<int> arr = {1,0,-1,0,-2,2};
    // vector<vector<int>> result = fourSumBrute(arr,0);
    vector<vector<int>> result = fourSumBetter(arr,0);
    for(auto vec : result){
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}