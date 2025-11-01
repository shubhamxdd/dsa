#include <bits/stdc++.h>
using namespace std;

void reverseStr(string &str){
    int start = 0;
    int end = str.size()-1;

    while(end>start){
        swap(str[start],str[end]);
        start++;
        end--;
    }

}

int main(){
    // character arrays
    char str[] = {'s','h','h','\0'}; // string is array of characters end it with '\0'
    char name[]= "shubham";
    string name1 = "shubhamm";
    // cout << name << endl;

    // to take string input from user, use getline(cin,varName) function
    // if we use cin, and provide it with "hello world", it ignores everything after space
    // string name2;
    // getline(cin,name2); 

    // cout << name2;

    cout << "before: ";
    cout << name1 << endl;
    
    reverseStr(name1);
    
    cout << "after: ";
    cout << name1 << endl;

    return 0;
}