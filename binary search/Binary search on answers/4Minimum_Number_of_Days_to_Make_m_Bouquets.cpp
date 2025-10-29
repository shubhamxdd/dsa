#include <bits/stdc++.h>
using namespace std;

int findMinElemVector(vector<int> vec){
    int min = vec[0];
    for (int i = 1; i < vec.size(); i++){
        if(vec[i]<min){
            min = vec[i];
        }
    }
    return min;
    
}

int findMaxElemVector(vector<int> vec){
    int max = vec[0];
    for(int i = 1;i<vec.size();i++){
        if(vec[i]>max){
            max = vec[i];
        }
    }
    return max;
}

bool isPossibile(vector<int> bloomDay, int day, int m, int k){
    int count = 0;
    int num_of_bouquets = 0;

    for(int i = 0;i<bloomDay.size()-1;i++){
        if(bloomDay[i]<=day){
            // flower is bloomed 
            // increase counter
            count++;
        }else {
            // if flower not bloomed
            // check how many bouquets can be made from current consequtive flowers (i.e. count) count/k
            // then reset counter
            num_of_bouquets += (count/k);
            count = 0;
        }
    }
    num_of_bouquets += (count/k);
    if(num_of_bouquets >=m) return true;
    return false;
}

int minDays(vector<int> bloomDay, int m, int k){
    if(m*k>bloomDay.size()) return -1;

    int min = findMinElemVector(bloomDay);
    int max = findMaxElemVector(bloomDay);

    // run from min elem to max elem in array
    for(int i = min;i<=max;i++){
        if(isPossibile(bloomDay,i,m,k) == true){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,3,5,1,9,4};
    // cout << findMinElemVector(nums) << endl;
    // cout << findMaxElemVector(nums) << endl;
    cout << minDays(nums,3,2) << endl;
    return 0;
}