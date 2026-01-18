#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int lsum = 0;
    int rsum = 0;
    int maxSum = 0;

    for(int i = 0;i<k;i++){
        lsum+=cardPoints[i];
    }
    maxSum=lsum;
    int rightIndex = cardPoints.size() - 1;

    for(int i = k-1;i>=0;i--){
        lsum-=cardPoints[i];
        rsum+=cardPoints[rightIndex];
        rightIndex--;
        maxSum = max(maxSum,lsum+rsum);
    }
    return maxSum;

}

int main(){
    vector<int> arr = {1,2,3,4,5,6,1};
    int k = 3;
    cout << maxScore(arr,3);
    return 0;
}