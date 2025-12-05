#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> st;

    for(int i = 0;i<s.length();i++){
        if(s[i] == '(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }else{
            if(st.empty()) return false;

            char elem = st.top();
            st.pop();
            if(s[i]==')' && elem=='(' || s[i]=='}' && elem=='{' || s[i]==']' && elem=='[' ){
                continue;
            }else {
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    return 0;
}