#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;

//adjacency list
vector<int>adjList[N];

//booleen array
bool visited[N];

//level array
int level[N];

//bfs implementation
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    if(!q.empty()){
        //pop a node from the queue and insert unvisited node of that queue
        int u= q.front();
        q.pop();
        cout<<"Visiting Node: "<<" "<<u<<endl;
        //section 1: a node is being processed
        for(int v: adjList[u]){
            //section 2:child processing
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            level[v]=level[u]+1;
            //section 3: child processing
        }
        //section 4: same as section one

    }

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
    bfs(1);

    //level print
    for(int i=0; i<n; i++){
        cout<<"Level of Node "<<i<<":  "<<level[i]<<endl;
    }
    
    return 0;
}