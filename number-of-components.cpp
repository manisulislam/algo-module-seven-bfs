#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

//adjacency list
vector<int>adjList[N];

//visited array
bool visited[N];


//dfs implementation
void dfs(int u){
    visited[u]=true;
    for(int v: adjList[u]){
        if(visited[v]==true) continue;
        dfs(v);
    }
}

//bfs implementation
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    if(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adjList[u]){
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }
    

    //connected components
    int cc=0;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        dfs(i);
        cc++;
    }

    //print number of connected components 
    cout<<"Number of connected components number:"<<cc<<endl;
    return 0;
}