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

vector<vector<int>> threeSumOptimal(vector<int> &nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;

    for(int i = 0;i<nums.size();i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = nums.size() - 1;

        while(j<k){
            // 3 cases
            int sum = nums[i] + nums[j] + nums[k];
            if(sum>0){
                // decrease the sum
                k--;
            }else if(sum<0){
                // increase the sum
                j++;
            }else{
                // sum == 0 , found triplet
                vector<int> triplet = {nums[i],nums[j],nums[k]};
                ans.push_back(triplet);
                j++; 
                k--;
                // move both elements to a new element
                while(j<k && nums[j] == nums[j-1])j++;
                while(j<k && nums[k] == nums[k+1])k--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    // vector<vector<int>> result = threeSumBrute(arr);
    // vector<vector<int>> result = threeSumBetter(arr);
    vector<vector<int>> result = threeSumOptimal(arr);
    for(auto vec : result){
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}