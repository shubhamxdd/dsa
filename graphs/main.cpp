#include<bits/stdc++.h>
using namespace std;


void adjMatrixGraph(){
    int n,m; // m edges, n nodes
    cin >> n >> m;
    vector<vector<int>> adjacentMatrix(n+1, vector<int>(n+1,0));


    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        
        adjacentMatrix[x][y] = 1;
        adjacentMatrix[y][x] = 1;
    }
    // print it

    for(vector<int> mat:adjacentMatrix){
        for(int v:mat){
            cout << v << " ";
        }
        cout << endl;
    }

}

void adjListGraph(){
    int n,m; // m edges, n nodes
    cin >> n >> m;
    vector<int> adjList[n+1];

    for(int i = 0;i<m;i++){
        int x,y;

        cin >> x >> y;

        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    // print it
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    
}

int main(){

    adjMatrixGraph();
    adjListGraph();

    return 0;
}