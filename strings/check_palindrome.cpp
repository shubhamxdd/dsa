#include <bits/stdc++.h>
using namespace std;

// string toLowercase(string &s)
// {
//     int size = s.length();
//     string str;
//     for (int i = 0; i < size; i++)
//     {
//         if (s[i] >= 'A' && s[i] <= 'Z'){
//             s[i] = s[i] + 32;
//             str.push_back(s[i]);
//         }else{
//             str.push_back(s[i]);
//         }
//     }
//     return str;
// }

// string filterString(const string &s)
// {
//     string filtered = "";
//     for (char c : s)
//     {
//         if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
//         {
//             filtered += c;
//         }
//     }
//     return filtered;
// }

// bool checkPalindrome(string s)
// {
//     int low = 0;
//     int high = s.size() - 1;

//     while (high > low)
//     {
//         if (s[low] != s[high])
//             return false;
//         low++;
//         high--;
//     }
//     return true;
// }
// int main()
// {
//     // string str = "shubham";
//     // string str1 = "racecar";
//     string str1 = "RacECAR+||,,.";

//     string lowercaseStr= toLowercase(str1);
//     string filteredStr = filterString(lowercaseStr);
//     // cout << checkPalindrome(str) << endl;
//     // cout << checkPalindrome(str1) << endl;
//     cout << filteredStr << endl;

//     // int numberOfTestCases;
//     // cin >> numberOfTestCases;
//     // while (numberOfTestCases--)
//     // {
//     //     string s;
//     //     getline(cin, s);
//     //     toLowercase(s);
//     //     string f_string = filterString(s);
//     //     cout << f_string << endl;
//     //     if (checkPalindrome(f_string))
//     //     {
//     //         cout << "1 (palindrome)" << endl;
//     //     }
//     //     else
//     //     {
//     //         cout << "0 (not palindrome)" << endl;
//     //     }
//     // }
//     // cout << checkPalindrome("madam");
//     // cout << checkPalindrome("racecar");
//     // cout << checkPalindrome("shubham");
//     // cout << checkPalindrome("xdxdx");
//     return 0;
// }



    string toLowercase(string s){
        string str;
        for(int i = 0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = s[i] + 32;
                str.push_back(s[i]);
            }else{
                str.push_back(s[i]);
            }
        }
        return s;
    }
    string filterString(string s){
        string f_str;
        for(int i = 0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                f_str.push_back(s[i]);
            }
        }
        return f_str;
    }
    bool isPalindrome(string s) {
        string lcString = toLowercase(s);
        string filteredStr = filterString(lcString);

        int low = 0;
        int high = filteredStr.size()-1;

        while(high>=low){
            if(filteredStr[low]!=filteredStr[high]) return false;
            low++;
            high--;
        }
        return true;



    }
    int main(){
        string s = "madam";
        cout << isPalindrome(s);
        return 0;
    }