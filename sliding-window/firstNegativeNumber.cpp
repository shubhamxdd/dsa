class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
        queue<int> q;
        
        while(j<n){
            if(arr[j] < 0){ // push negative number in queue
                q.push(arr[j]);
            }
            // check if window size is reached
            if(j-i+1 == k){
                if(!q.empty()) ans.push_back(q.front());
                else ans.push_back(0);
            // shift window
                if(arr[i] < 0){
                    q.pop();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
