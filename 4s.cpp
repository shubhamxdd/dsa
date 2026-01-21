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

vector<vector<int>> fourSumOptimal(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i = 0;i<n;i++){
        // should not be same as previous element
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1;j<n;j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;

            while(k<l){
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                if(sum>target)l--;
                else if(sum<target)k++;
                else {
                    // both are equal
                    // quad found
                    vector<int> quad = {nums[i],nums[j],nums[k],nums[l]};
                    // no need to sort as we sorted the array in first step
                    ans.push_back(quad);
                    k++;
                    l--;
                    // now move k and l pointer to a new value which is not same as previous
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }

        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,0,-1,0,-2,2};
    // vector<vector<int>> result = fourSumBrute(arr,0);
    // vector<vector<int>> result = fourSumBetter(arr,0);
    vector<vector<int>> result = fourSumOptimal(arr,0);
    for(auto vec : result){
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}