#include <bits/stdc++.h>
using namespace std;

void removeOccurence(string &s, string &part){
    
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    
    int pos;
    while((pos=s.find(part)) !=string::npos){
        s.erase(pos,part.size());
        cout << s << endl;
    }

    cout << s;

    return 0;
}