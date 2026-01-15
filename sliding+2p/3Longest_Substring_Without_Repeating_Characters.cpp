#include <bits/stdc++.h>
using namespace std;

int longestSequenceBrute(string s){
    int maxLen = 0;
    for(int i = 0;i<s.size();i++){
        int hashArr[256] = {0};
        for(int j = i;j<s.size();j++){
            if(hashArr[s[j]] == 1) break;
            int len = j-i+1;
            maxLen = max(maxLen,len);
            hashArr[s[j]] = 1;
        }
    }
    return maxLen;
    
}

int longestSequenceOptimal(string s){
    int hashArr[256] = {-1};
    fill(hashArr,hashArr+256,-1);
    int maxLen = 0;
    int n = s.size();
    int l = 0;
    int r = 0;

    while(r<n){
        // check if exist in map
        if(hashArr[s[r]] != -1){
            // means exist
            if(hashArr[s[r]] >= l){
                l = hashArr[s[r]] + 1;
            }
        }
        int len = r - l + 1;
        maxLen = max(maxLen,len);
        hashArr[s[r]] = r;
        r++;
    }
    return maxLen;
}


int main(){
    string s = "abcabcbb";
    // cout << longestSequenceBrute(s);
    cout << longestSequenceOptimal(s);
    return 0;
}