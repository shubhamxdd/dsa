#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adjList,vector<int> &visited){
    visited[node]=1;
    for(int it: adjList[node]){
        if(!visited[it]){
            dfs(it,adjList,visited);
        }
    }
    
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int cnt = 0;

    // convert adj matrix to adj list
    int n = isConnected.size();
    vector<vector<int>> adjList(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(isConnected[i][j] == 1 && i != j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> visited(n,0);
    for(int i = 0;i<n;i++){
        if(visited[i]==0){
            cnt++;
            dfs(i,adjList,visited);
        }
    }
    return cnt;

}

int main(){
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout << findCircleNum(isConnected);
    return 0;
}