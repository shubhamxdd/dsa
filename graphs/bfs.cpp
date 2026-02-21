#include<bits/stdc++.h>
using namespace std;

// create adjacency list
// vector<vector<int>> createAdjList(int nodesNum, vector<pair<int,int>> edges){
//     vector<vector<int>> adjList(nodesNum+1);

//     for(int i = 0;i<edges.size();i++){
//         int x = edges[i].first;
//         int y = edges[i].second;
//         adjList[x].push_back(y);
//         adjList[y].push_back(x);
//     }
//     return adjList;
// }

vector<int> bfsGraph(int nodesNum, vector<int> adjList[]){
    vector<int> ans;
    vector<int> visited(nodesNum+1,0);
    queue<int>q;

    q.push(0);
    visited[0] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(int neigh: adjList[frontNode]){
            if(visited[neigh] == 0){
                visited[neigh] = 1;
                q.push(neigh);
            }
        }
    }
    return ans;


}

int main(){
    int nodesNum = 5;
    vector<int> adjList[5];
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0};
    adjList[3] = {1};
    adjList[4] = {1};

    vector<int> bfs = bfsGraph(nodesNum, adjList);

    for(int node : bfs){
        cout << node << " ";
    }
    cout << endl;
    return 0;
}