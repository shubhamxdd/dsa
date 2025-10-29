#include <bits/stdc++.h>
using namespace std;

int maxInVector(vector<int> vec){
    int max = vec[0];
    for(int i = 1;i<vec.size();++i){
        if(vec[i]>max){
            max = vec[i];
        }
    }
    return max;
}

long long computeTimeTaken(vector<int> piles, int mid){
    long long timeTaken = 0;
    for(int pile:piles){
        timeTaken += ceil((double)pile/(double)mid);
    }
    return timeTaken;
}


int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = maxInVector(piles);
    int ans = -1;

    while(high>=low){
        int mid = (low+high)/2;
        // time taken by each pile at rate of mid, calculate and add all
        long long totalTimeTaken = computeTimeTaken(piles,mid);

        if(totalTimeTaken<=h){
            // eliminate right
            ans = mid;
            high = mid - 1;
        } else {
            // eliminate left
            low = mid + 1;
        }
    }
    return ans;
}


int main(){
    vector<int> nums = {1,2,3,4,88,6,3,1,6,};
    // cout << findMaxInVector(nums) << endl;
    // vector<int> pilesVal = {3,6,7,11};
    vector<int> pilesVal = {30,11,23,4,20};
    // cout << brute(pilesVal,8) << endl;
    cout << minEatingSpeed(pilesVal,5) << endl;
    return 0;
}