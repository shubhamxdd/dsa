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

int main(){
    string s = "abcabcbb";
    cout << longestSequenceBrute(s);
    return 0;
}