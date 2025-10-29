#include <bits/stdc++.h>
using namespace std;

int findMaxInVector(vector<int> arr){
    int max = arr[0];
    for(int i = 1;i<arr.size();++i){ // why ++i
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int calculateTotalHours(vector<int> piles,int rate){
    int totalHours = 0;
    for (int p : piles){
        totalHours += ceil((double)p/(double)rate);
    }
    return totalHours;
    
}

int brute(vector<int> piles,int h){
    // find max in piles arr and run loop from 1 to max
    int maxInVector = findMaxInVector(piles);
    for(int i = 1;i<=maxInVector;i++){
        int reqTime = calculateTotalHours(piles,i); // TODO
        if(reqTime<=h) return i;
    }
    return -1;
}

int binary_search_on_answer(vector<int> piles,int h){
    int low = 1;
    int high = findMaxInVector(piles);
    int ans = -1;

    while(high>=low){
        int mid = (low+high)/2;

        int timeTakenAtMidRate = calculateTotalHours(piles, mid);

        if(timeTakenAtMidRate > h){
            // eliminate left
            low = mid + 1;
        }
        else {
            // eliminate right
            ans = mid;
            high = mid - 1;
        }
        // else if(timeTakenAtMidRate <= h) {
        //     // eliminate right
        //     high = mid - 1;
        // }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4,88,6,3,1,6,};
    // cout << findMaxInVector(nums) << endl;
    // vector<int> pilesVal = {3,6,7,11};
    vector<int> pilesVal = {30,11,23,4,20};
    // cout << brute(pilesVal,8) << endl;
    cout << binary_search_on_answer(pilesVal,5) << endl;
    return 0;
}