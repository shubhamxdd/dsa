#include <bits/stdc++.h>
using namespace std;

int countInversionsBrute(vector<int> &arr){
    int n = arr.size();
    int count = 0;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[i]>arr[j] && i<j){
                count++;
            }
        }
    }

    return count;

}




int main(){
    vector<int> arr = {6,3,5,2,7};
    cout << countInversionsBrute(arr);
    return 0;
}