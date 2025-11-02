#include <bits/stdc++.h>
using namespace std;

string toLowercase(string s){
    string str;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
            str.push_back(s[i]);
        }
        else
        {
            str.push_back(s[i]);
        }
    }
    return s;
}

string filterString(string s){
    string f_str;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            f_str.push_back(s[i]);
        }
    }
    return f_str;
}

bool isPalindrome(string s){
    string lcString = toLowercase(s);
    string filteredStr = filterString(lcString);

    int low = 0;
    int high = filteredStr.size() - 1;

    while (high >= low)
    {
        if (filteredStr[low] != filteredStr[high])
            return false;
        low++;
        high--;
    }
    return true;
}

bool isAlphanumeric(char c){
    if(c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9')return true;
    return false;
}

bool isPalindromeBetter(string s){
    int start = 0;
    int end = s.size()-1;

    while(end>start){
        // check is num is alphanumeric or not
        if(!isalnum(s[start])) start++;
        if(!isalnum(s[end])) end--;

        if(tolower(s[start] != tolower(s[end]))) return false;
        else{
            start++;
            end--;
        }
    }
    return true;
}

int main(){
    string s = "madam";
    // cout << isPalindromeBetter(s);
    cout << isAlphanumeric('2');
    return 0;
}