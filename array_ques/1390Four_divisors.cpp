#include<bits/stdc++.h>
using namespace std;

int sumFourDivisorsBrute(vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
        int divCount = 0;
        int localTotal = 0;
        for (int j = 1; j <= nums[i]; j++) {
            if (nums[i] % j == 0) {
                divCount++;
                localTotal += j;
            }
        }
        if (divCount == 4) {
            total += localTotal;
        }
    }
    return total;
}

int sumFourDivisorsOptimal(vector<int>& nums) {
    int total = 0;

    for (int i = 0; i < nums.size(); i++) {
        int divCnt = 0;
        int sum = 0;
        // for (int j = 1; j <= sqrt(nums[i]); j++) {
        for (int j = 1; j * j <= nums[i]; j++) {
            if (nums[i] % j == 0) {
                // one factor is j, other is nums[i]/j
                int fact2 = (nums[i] / j);

                if (fact2 == j) {
                    divCnt += 1;
                    sum += fact2;
                } else {
                    divCnt += 2;
                    sum += fact2 + j;
                }
                if (divCnt > 4)
                    break;
            }
        }
        if (divCnt == 4)
            total += sum;
    }
    return total;
}


int main(){
    vector<int> nums = {21, 4, 7};
    cout << sumFourDivisorsBrute(nums) << endl;
    cout << sumFourDivisorsOptimal(nums) << endl;

    return 0;
}