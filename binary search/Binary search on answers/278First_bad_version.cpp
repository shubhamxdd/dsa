#include<bits/stdc++.h>
using namespace std;


int isBadVersion(int version){
    // dummy function
    return version>=4;
}

int firstBadVersionBrute(int n) {
    // brute
    for(int i = 1;i<=n;i++){
        if(isBadVersion(i) ==  true){
            return i;
        }
    }
    return 1;
}

int firstBadVersion(int n) {
        long long low = 1;
        long long high = n;

        long long ans = n;

        while(high>=low){
            long long mid = (low+high)/2;

            if(isBadVersion(mid) == true){
                // this can be answer
                ans = mid;
                high=mid-1;
            }else {
                // found bad version
                // ans will be on left so eliminate right
                low=mid+1;
            }
        }
        return ans;
}


int main(){
    return 0;
}