#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    else return -1;

}

string converstion(string infix){
    string ans = "";
    stack<char> st;
    int i = 0;

    while(i<infix.length()){
        if((infix[i] >= 'A' && infix[i]<='Z') || 
        (infix[i]>='a' && infix[i]<='z') || 
        (infix[i]>='0' && infix[i]<='9')){
            ans+=infix[i];
        }else if(infix[i]=='('){
            st.push(infix[i]);
        }else if(infix[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }else {
            // operands
            while(!st.empty() && priority(infix[i]) <= priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

int main(){
    string infixStr = "a+b*(c^d-e)";
    cout << converstion(infixStr) << endl; 
    return 0;
}