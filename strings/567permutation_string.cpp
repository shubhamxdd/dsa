#include <bits/stdc++.h>
using namespace std;

bool isFreqSame(int arr1[], int arr2[]){
    for(int i = 0;i<26;i++){
        if(arr1[i] != arr2[i]) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    int freqArr[26] = {0};
    // store freq of s1 characters in freqArr
    for(int i = 0;i<s1.size();i++){
        freqArr[s1[i]-'a']++;
    }

    int windowSize = s1.length();

    for(int i = 0;i<s2.length();i++){
        int windowIdx = 0;
        int idx = i;

        // make freqArr to store of inside window
        int freqArrWindow[26]={0};

        while(windowIdx<windowSize && idx<s2.length()){
            freqArrWindow[s2[idx]-'a']++;
            windowIdx++;
            idx++;
        }

        if(isFreqSame(freqArr,freqArrWindow)){
            return true;
        }
    }
    return false;
}


int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << checkInclusion(s1,s2);
    return 0;
}