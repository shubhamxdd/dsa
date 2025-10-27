#include <bits/stdc++.h>
using namespace std;

// brute
int square_root(int num){
    int ans = 1;
    for(int i = 0;i<=num;i++){
        if(num>=i*i){
            ans = i;
        }else{
            break;
        }
    }
    return ans;
}

int square_root_binary_search(int num){
    int low = 1;
    int high = num - 1;
    int ans = 1;

    while(high>=low){
        int mid = (low+high)/2;

        if(mid*mid<=num){
            // update ans and eliminate right
            ans = mid;
            // eliminate left
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    // to save space return high instead of using additional variable, as high will point to answer in last iteration
    cout << "from function, high => " << high << endl;
    return ans;
}

int main(){
    // cout << square_root(15);
    cout << square_root_binary_search(15) << endl;;
    return 0;
}