#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int cnt = 0;

    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int l = 0;
    int r = 0;

    while(l<s.size() && r<g.size()){
        if(g[r]<=s[l]){
            l++;r++;cnt++;
        }
        l++;
    }
    return cnt;
}

int main(){
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};

    cout<<findContentChildren(g,s)<<endl;

    return 0;
}