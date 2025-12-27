#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr){
    vector<int> ansArr(arr.size(),-1);

    for(int i = 0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[i]<arr[j]){
                ansArr[i] = arr[j];
                break;
            }
        }
    }
    return ansArr;
}

vector<int> nextGreaterElementOptimal(vector<int> &arr){
    // vector<int> ansArr(arr.size(),-1);
    vector<int> ansArr(arr.size(),0);
    stack<int> st;

    for(int i = arr.size()-1;i>=0;i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ansArr[i] = -1;
        } else {
            ansArr[i] = st.top();
        }
        st.push(arr[i]);
    }
return ansArr;
}

vector<int> nextGreaterElementLC(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m; // nums2 value and its NGE
    stack<int> s;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }
        if(s.empty()){
            m[nums2[i]] = -1;
        }else{
            m[nums2[i]] = s.top();
        }
        s.push(nums2[i]);
    }

    vector<int> ans; // find values of num1 in map and push that in ans arr
    for(int i = 0;i<nums1.size();i++){
        ans.push_back(m[nums1[i]]);
    }
return ans;
}


int main(){
    vector<int> arr = {6,0,8,1,3};
    vector<int> ans= nextGreaterElementOptimal(arr);

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
