#include <bits/stdc++.h>
using namespace std;

int findLargestInVector(vector<int> &arr){
    int maxV = -1;
    for(int i = 0;i<arr.size();i++){
        if(arr[i]>maxV){
            maxV = arr[i];
        }
    }
    return maxV;
}

int findSumOfVector(vector<int> &arr){
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum+= arr[i];
    }
    return sum;
}

// days took to ship weights in specified capacity
int calculateDaysTaken(vector<int> &weights, int capacity){
    // first day
    int days = 1;
    // sum of weights are 0 that are loaded in ship i.e. empty
    int load = 0;

    for(int i=0;i<weights.size();i++){
        if(load + weights[i] > capacity){
            days++;
            load = weights[i];
        }else{
            load +=weights[i];
        }
    }
    return days;
}


int shipWithinDaysBrute(vector<int>& weights, int days){
    int maxW = findLargestInVector(weights);
    int sum = findSumOfVector(weights);
    for(int capacity = maxW;capacity<=sum;capacity++){
        int daysTaken = calculateDaysTaken(weights, capacity);
        // if(daysTaken <=days) return daysTaken;
        if(daysTaken <=days) return capacity;
    }
    return sum;
}

int shipWithinDays(vector<int> &weights, int days){
    int low = findLargestInVector(weights);
    int high = findSumOfVector(weights);

    while(high>=low){
        int mid = (low+high)/2;
        int daysTaken = calculateDaysTaken(weights, mid);

        if(daysTaken<=days){
            // eliminate right as it is a possible answer and we need to find small
            high = mid -1;
        }else {
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    // cout << shipWithinDaysBrute(nums,5) << endl;
    cout << shipWithinDays(nums,5) << endl;
    return 0;
}