#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
//#include<set>
#include<vector>
#include<limits>
#include<algorithm>
#include<queue>
#define int long long
class graph{
    public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs(int src,int n){
        unordered_map<int,bool>vis;
        unordered_map<int,int>parent;
        vector<int>dist(n+1,INT_MAX);
        dist[src] = 0;
        queue<int>q;
        q.push(src);
        vis[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            // if(parent[top] != -1){
            //     dist[top] = min(1 + dist[parent[top]],dist[top]);
            // }
            for(auto nbr : adj[top]){
                if(!vis[nbr]){
                    parent[nbr] = top;
                    vis[nbr] = true;
                    dist[nbr] = min(1 + dist[top],dist[nbr]);
                    q.push(nbr);
                }
            }
        }
        return dist;
    }

};

signed main(){
    int n = 7;
    graph g;
    g.addEdge(1,2);
    g.addEdge(1,5);
    g.addEdge(1,5);
    g.addEdge(3,2);
    g.addEdge(5,4);
    g.addEdge(7,4);
    g.addEdge(7,6);
    g.addEdge(3,4);
    vector<int>ans = g.bfs(4,7);
    for(int i=1;i<n+1;i++){
        cout<<ans[i]<<" ";
    }
    
}