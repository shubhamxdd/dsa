#include <bits/stdc++.h>
using namespace std;

int power(int base, int pwr){
    int ans = 1;
    for(int i = 0;i<pwr;i++){
        ans *=base;
    }
    return ans;
} // instead use inbuilt pow function as it takes less time complexity which is O(log N)

int nth_root_brute(int num, int exponent){
    for(int i = 0;i<num;i++){
        if(power(i,exponent) == num ){
            return i;
        }else if(power(i,exponent)>num){
            break;
        }
    }
    return -1;
}

int funcn(int mid, int target, int exponent){
    long long ans = 1;
    for (int i = 1; i <= exponent; i++){
        ans *= mid;
        if(ans>target) return 2;
        else if(ans == target) return 0;
    }
    return 1;
    
}

int nth_root_binary_search(int num, int exponent){
    int low = 1;
    int high = num;

    while(high>=low){
        int mid = (low+high)/2;
        if(power(mid,exponent) == num) return mid; // mid is answer
        else if(power(mid,exponent)>num) {
            // answer is in left eliminate right
            high = mid - 1;
        } else {
            // answer is in right, elimninate left
            low = mid + 1;
        }
    }
    return -1;
}


int nth_root_binary_search_optimized(int num, int exponent){
    int low = 1;
    int high = num;

    while(high>=low){
        int mid = (low+high)/2;
        int midN = funcn(mid,num,exponent);
        if(midN == 0) return mid; // mid is answer mid^exp = ans
        else if(midN == 2) {
            // answer is in left eliminate right, mid^exp > ans
            high = mid - 1;
        } else { // midN = 1
            // answer is in right, elimninate left, mid^exp < ans
            low = mid + 1;
        }
    }
    return -1;
}


int main(){
    // cout << nth_root_brute(81, 4) << endl;
    // cout << nth_root_brute(81,4) << endl;
    cout << nth_root_binary_search_optimized(81,4) << endl;
    return 0;
}