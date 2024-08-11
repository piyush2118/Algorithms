#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
using namespace std;

class Graph{
    public:
    bool isDir;
    unordered_map<int,list<pair<int,int> > >adj;
    void addEdge(int src,int con,int wt,bool isDir){
        if(isDir){
            adj[src].push_back(make_pair(con,wt));
        }else{
            adj[src].push_back(make_pair(con,wt));
            adj[con].push_back(make_pair(src,wt));
        }
    }
    void bfs(int src,unordered_map<int,bool>&vis){
        queue<int> q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            int temp = q.front();
            cout<<temp<<" ";
            q.pop();
            for(auto nbr: adj[temp]){
                
                if(!vis[nbr.first]){
                    q.push(nbr.first);
                    vis[nbr.first]  = true;
                }
                    

            }
        }
    }
    void dfs(int src,unordered_map<int,bool>&vis){
        vis[src] = true;
        cout<<src<<" ";
        for(auto i: adj[src]){
            if(!vis[i.first]){
                dfs(i.first,vis);
            }
        }
    }
    bool detectBfs(int src,unordered_map<int,bool>&vis){
        queue<int> q;
        unordered_map<int,int> parent;
        q.push(src);
        parent[src] = -1;
        vis[src] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            
            for(auto nbr:adj[t]){
                if(!vis[nbr.first]){
                    vis[nbr.first] = true;
                    q.push(nbr.first);
                    parent[nbr.first] = t;
                }else{
                    if(nbr.first != parent[t]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool detectDfs(int src,unordered_map<int,bool>&vis,unordered_map<int,int>&parent){
        vis[src] = true;
        for(auto nbr:adj[src]){
            if(!vis[nbr.first]){
                parent[nbr.first] = src;
                bool ans = detectDfs(nbr.first,vis,parent);
                if(ans) return true;
            }else{
                if(nbr.first != parent[src]){
                    return true;
                }
            }
        }
        return false;
    }
    bool detect(int src,unordered_map<int,bool>&vis,unordered_map<int,bool>&dfsvis){
        vis[src] = true;
        dfsvis[src] = true;
        for(auto i:adj[src]){
            if(!vis[i.first]){
                bool ans = detect(i.first,vis,dfsvis);
                if(ans) return true;
            }else{
                if(dfsvis[i.first] == true){
                    return true;
                }
            }
        }
        dfsvis[src] = false;
        return false;
    }
    void tsdfs(int src,stack<int>&s,unordered_map<int,bool>&vis){
        vis[src] = true;
        for(auto i: adj[src]){
            if(!vis[i.first]){
                tsdfs(i.first,s,vis);
            }
        }
        s.push(src);
    }
    void tsbfs(int src,unordered_map<int,bool>&vis,unordered_map<int,int>&indeg){
        queue<int> q;
        for(auto i : adj){
            for(auto j: i.second){
                indeg[j.first]+=1;
            }
        }
        for(auto i:adj){
            if(indeg[i.first] == 0){
                q.push(i.first);
            }
        }

        while(!q.empty()){
            int temp = q.front();
            cout<<temp<<" ";
            q.pop();
            for(auto i: adj[temp]){
                indeg[i.first]-=1;
                if(indeg[i.first] == 0){
                    q.push(i.first);
                }
            }
        }
    }
    void shortestpathbfs(int src,int dest,unordered_map<int,bool>&vis){
        queue<int> q;
        unordered_map<int,int> parent;
        q.push(src);
        parent[src] = -1;
        vis[src] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            
            for(auto nbr:adj[t]){
                if(!vis[nbr.first]){
                    vis[nbr.first] = true;
                    q.push(nbr.first);
                    parent[nbr.first] = t;
                }
            }
        }
        vector<int> ans;
        int node = dest;
        while(node != -1){
            ans.push_back(node);
            node = parent[node];
        }
        reverse(ans.begin(),ans.end());
        for(int i:ans){
            cout<<i<<" ";
        }
    }
    void shortp(int src,int dest,unordered_map<int,bool>&vis){
        queue<int> q;
        unordered_map<int,int> parent;
        q.push(src);
        parent[src] = -1;
        vis[src] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(pair<int,int> p: adj[t]){
                if(!vis[p.first]){
                    vis[p.first] = true;
                    parent[p.first] = t;
                    q.push(p.first);
                }
            }

        }
        vector<int> v;
        int node = dest;
        while(node!=-1){
            v.push_back(node);
            node = parent[node];
        }
        reverse(v.begin(),v.end());
        for(int i:v){
            cout<<i<<" ";
        }
    }
    void topsortdfs(int src,stack<int>&s,unordered_map<int,bool>&vis){
        vis[src] = true;
        for(auto i:adj[src]){
            if(!vis[i.first]){
                topsortdfs(i.first,s,vis);
            }
        }
        s.push(src);
    }
    void topsortbfs(int src){
        queue<int> q;
        unordered_map<int,int> indeg;
        vector<int> v;
        for(auto i:adj){
            for(auto j:adj[i.first]){
                indeg[j.first]+=1;
            }
        }
        for(auto i:indeg){
            if(i.second == 0){
                q.push(i.first);
                //v.push_back(i.first);
            }
        }
        while(!q.empty()){
            int t = q.front();
            v.push_back(t);
            q.pop();
            for(auto i:adj[t]){
                indeg[i.first] -= 1;
                if(indeg[i.first] == 0){
                    q.push(i.first);
                    
                }
            }
        }
    }

};

int main(){
    Graph g;
    unordered_map<int,bool> vis;
    unordered_map<int,bool> dfsvis;
    unordered_map<int,int> indeg;
    g.addEdge(1,2,1,1);
    g.addEdge(2,3,1,1);
    g.addEdge(3,4,1,1);    
    g.addEdge(1,6,1,1);
    g.addEdge(6,4,1,1);
    //g.addEdge(6,5,1,0);
    g.addEdge(1,5,1,1);
    g.bfs(1,vis);
    cout<<endl;
    vis.clear();
    // g.dfs(1,vis);
    // cout<<endl;
    // vis.clear();
    // cout<<g.detectBfs(1,vis);
    // cout<<endl;
    // vis.clear();
    //unordered_map<int,int> parent;
    //cout << g.detect(1,vis,dfsvis);
    // stack<int> s;
    // g.tsdfs(1,s,vis);
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    //g.tsbfs(1,vis,indeg);
    g.shortp(1,4,vis);
}
