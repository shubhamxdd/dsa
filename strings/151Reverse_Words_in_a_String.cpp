#include <bits/stdc++.h>
using namespace std;

string reverseWords(string &s){
    string ans = "";
    // reverse string
    reverse(s.begin(),s.end());
    // cout << s << " 1" << endl;
    // loop over each word and put it in word variable, then reverse it
    for(int i = 0;i<s.size();i++){
        string word = "";
        // cout << word << " inside for" << endl;
        while(i<s.size() && s[i] != ' '){
            word+=s[i];
            i++;
            // cout << word << " inside while" << endl;
        }
        // reverse contents of variable word
        reverse(word.begin(),word.end());

        // cout << word << " outside while" << endl;
        
        // cout<< ans << " before" << endl;
        if(word.size()>0) ans += ' ' + word;
        
        // cout<< ans << " in" << endl;
    }
    // cout<< ans << " out" << endl;
    return ans.substr(1);
}

int main(){
    string s = "the pen";
    cout << reverseWords(s);
    return  0;
}