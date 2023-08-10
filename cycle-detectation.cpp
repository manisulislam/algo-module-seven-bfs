#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;

//adjacency list
vector<int>adjList[N];

//booleen array
bool visited[N];

//level array
int level[N];

//dfs implementation and cycle detection
bool dfs(int u, int p=-1){
    visited[u]=true;
    bool cycleExist=false;
    for(int v: adjList[u]){
        if(v==p) continue;
        if(visited[v]==true) return true;
        cycleExist=cycleExist|dfs(v,u);
    }
    return cycleExist;

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
    }
    bool isCycle=false;
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        isCycle|=dfs(i);
    }
    if(isCycle){
        cout<<"Cycle detected"<<endl;
    }
    else {
        cout<<"No Cycle detected"<<endl;
    }
    return 0;
}
