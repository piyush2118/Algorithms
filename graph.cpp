#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class Graph{
    public:
    unordered_map<T,list<pair<T,int> > > adj;
    bool isDirected;
    void create(T node,T con,int wt,bool isDirected){
        if(isDirected){
            adj[node].push_back(make_pair(con,wt));
        }else{
            adj[node].push_back(make_pair(con,wt));
            adj[con].push_back(make_pair(node,wt));
        }
    }
    void bfs(T src,unordered_map<T,bool >&vis){
        queue<T> q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            for(pair<T,int> p:adj[q.front()]){
                if(!vis[p.first]){
                    q.push(p.first);
                    vis[p.first] = true;
                }
            }
            cout<<q.front()<<" ";
            q.pop();
        }
    }
    void dfs(T src,unordered_map<T,bool >&vis){
        cout<<src<<" ";
        vis[src] = true;
        for(pair<T,int> p : adj[src]){
            if(!vis[p.first])
                dfs(p.first,vis);
        }
    }

};


int main(){
    Graph<char> g;
    unordered_map<char,bool > vis;
    g.create('a','b',1,0);
    g.create('a','c',1,0);
    g.create('a','d',1,0);
    g.create('b','c',1,0);
    g.create('b','e',1,0);
    g.create('c','e',1,0);
    g.create('d','f',1,0);
    g.bfs('a',vis);
    cout<<endl;
    vis.clear();
    g.dfs('a',vis);
}

        
        


    

    

