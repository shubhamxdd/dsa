#include <bits/stdc++.h>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& arr) {
    int n = arr.size();
    int time = 0;

    for (int i = 0; i < n - 1; i++) {
        int dx = abs(arr[i+1][0]-arr[i][0]);
        int dy = abs(arr[i+1][1]-arr[i][1]);
        time+=max(dx,dy);
    }
    return time;
}
int main(){
    vector<vector<int>> pts = {{1,1},{3,4},{-1,0}};
    cout << minTimeToVisitAllPoints(pts);
    return 0;
}