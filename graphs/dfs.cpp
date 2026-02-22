#include<bits/stdc++.h>
using namespace std;


void dfsRecursion(int node, vector<vector<int>> adjList,vector<int> &visited, vector<int> &ans){
    // mark as visited
    visited[node] = 1;
    ans.push_back(node);
    // traverse its neighbours
    for(int it: adjList[node]){
        if(!visited[it]) dfsRecursion(it,adjList,visited,ans);
    }
}


vector<int> dfsGraph(int nodesNum, vector<vector<int>> adjList){
    vector<int> ans;
    vector<int> visited(nodesNum+1,0);
    int start = 0;
    dfsRecursion(start,adjList,visited,ans);
    return ans;
}

int main(){
    int nodesNum = 5;
    vector<vector<int>> adjList(nodesNum);
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0};
    adjList[3] = {1};
    adjList[4] = {1};

    vector<vector<int>> adjList2(6);
    adjList2[0] = {1, 2, 3};
    adjList2[1] = {0, 4, 5};
    adjList2[2] = {0};
    adjList2[3] = {0};
    adjList2[4] = {1};
    adjList2[5] = {1};
    

    // vector<int> trav = dfsGraph(nodesNum,adjList);
    vector<int> trav = dfsGraph(6,adjList2);

    for(int v: trav){
        cout << v << " ";
    }


    return 0;
}