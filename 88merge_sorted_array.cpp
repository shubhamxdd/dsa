#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int idx = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[idx] = nums1[i];
            i--;
            idx--;
        } else {
            nums1[idx] = nums2[j];
            j--;
            idx--;
        }
    } // if this while loop completes there will be 2 cases;
        // elements of j array are not placed, so run another loop to do
        // no need to do anything in other case
    while (j >= 0) {
        nums1[idx] = nums2[j];
        j--;
        idx--;
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    merge(nums1, m, nums2, n);  
    for(int i: nums1){
        cout << i << " ";
    }
    return 0;
}