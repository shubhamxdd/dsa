#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    else return -1;

}

string fixBrackets(string st){
    for(int i = 0;i<st.size();i++){
        if(st[i] == ')'){
            st[i] = '(';
        }
        else if(st[i] == '('){
            st[i] = ')';

        }
    }
    // cout << st << endl;
    return st;
}

string converstion(string s){
    int i = 0;
    stack<char> st;
    string ans = "";
    cout<<s<<endl;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    s=fixBrackets(s);
    cout<<s<<endl;

    while(i < s.length()){
        if((s[i] >='A' && s[i]<='Z') || (s[i] >='a' && s[i]<='z') ||  (s[i] >='0' && s[i]<='9') ){
            ans+=s[i];
        }else if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();            
            }
            st.pop();
        }else {
            // operators
            if(s[i] == '^') {
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }else{
                while(!st.empty() && priority(s[i]) < priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        i++;
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    cout << ans << endl;
    reverse(ans.begin(),ans.end());
    cout << ans << endl;


    return ans;
}



int main(){
    string infixStr = "a+b*(c^d-e)";
    cout << converstion(infixStr) << endl; 
    return 0;
}