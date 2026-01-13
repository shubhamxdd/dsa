#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;

    while (r > l) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void getAllParts(string s, vector<string>& currPart, vector<vector<string>>& ans) {
    if (s.size() == 0) {
        ans.push_back(currPart);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        string part = s.substr(0, i + 1);
        if (isPalindrome(part)) {
            currPart.push_back(part);
            getAllParts(s.substr(i + 1), currPart, ans);
            currPart.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> currPart;
    getAllParts(s, currPart, ans);
    return ans;
}

int main(){
    string s = "aab";
    vector<vector<string>> result = partition(s);
    for (const auto& vec : result) {
        for (const auto& str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}