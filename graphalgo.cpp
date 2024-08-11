#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
class Graph{
    public:
    bool isDir;
    unordered_map<int,list<pair<int,int> > > adj;
    void addEdge(int src,int con,bool isDir,int wt){
        if(isDir){
            adj[src].push_back(make_pair(con,wt));
        }else{
            adj[src].push_back(make_pair(con,wt));
            adj[con].push_back(make_pair(src,wt));
        }
    }
    void topodfs(int src,unordered_map<int,bool>&vis,stack<int>&s){
        vis[src] = true;
        for(auto i:adj[src]){
            if(!vis[i.first]){
                topodfs(i.first,vis,s);
            }
        }
        s.push(src);
    }
    void topobfs(int dest,unordered_map<int,int>&indeg,vector<int>&v){
        for(auto i:adj){
            for(auto j:i.second){
                indeg[j.first]++;
            }
        }
        queue<int> q;
        for(auto i:adj){
            if(indeg[i.first] == 0){
                q.push(i.first);
            }
        }
        while(!q.empty()){
            int fnode = q.front();
            v.push_back(fnode);
            q.pop();
            for(auto i : adj[fnode]){
                indeg[i.first]--;
                if(indeg[i.first] == 0){
                    q.push(i.first);
                }
            }
        }
    }
    void shortestpathbfs(int src,int dest,unordered_map<int,bool>&vis,unordered_map<int,int>&parent){
        queue<int> q;
        q.push(src);
        parent[src] = -1;
        vis[src] = true;
        while(!q.empty()){
            int fnode = q.front();
            q.pop();
            for(auto i:adj[fnode]){
                if(!vis[i.first]){
                    q.push(i.first);
                    parent[i.first] = fnode;
                }
            }
        }
        int node = dest;
        vector<int> v;
        while(node != -1){
            v.push_back(node);
        }
        reverse(v.begin(),v.end());
        for(auto i: v){
            cout<<i<<" ";
        }
    }
    void shortestweightedpath(int src,int dest,stack<int>&s){
        unordered_map<int,int> val;
        for(auto i:adj){
            val[i.first] = INT_MAX;
        }val[s.top()] = 0;
        while(!s.empty()){
            int fnode = s.top();
            s.pop();
            for(auto i:adj[fnode]){
                val[i.first] = min(val[i.first],val[fnode] + i.second);
            }
        }
        cout<<val[dest]<<endl;

    }
    void djikstra(int src,int dest){
        set<pair<int,int> > st;
        unordered_map<int,int> mp;
        mp[src] = 0;
        st.insert(make_pair(0,src));
        while(!st.empty()){
            auto fnode = *(st.begin());
            st.erase(fnode);
            int dist = fnode.first;
            int node = fnode.second;
            for(auto i: adj[node]){
                if(mp[i.first] > i.second + dist){
                    auto itr = st.find(make_pair(mp[i.first],i.first));
                    if(itr != st.end()){
                        st.erase(itr);
                    }
                    
                }
                mp[i.first] =  i.second + dist;
                st.insert(make_pair(mp[i.first],i.first));

            }
        }
        cout<<mp[dest]<<endl;
    }
    void bellamford(int src,int n){
        vector<int> v(n,INT_MAX);
        v[src] = 0;
        
        for(int i=1;i<n;i++){
            for(auto i:adj){
                for(auto j:i.second){
                    //relaxation
                    int tonode = j.first;
                    int node = i.first;
                    int dist = j.second;
                    if(v[node] != INT_MAX && v[tonode] > dist + v[node]){
                        v[tonode] = dist + v[node];
                    }
                }
            }
        }
        bool flag = false;
        for(auto i:adj){
            for(auto j:i.second){
                //relaxation
                int tonode = j.first;
                int node = i.first;
                int dist = j.second;
                if(v[node] != INT_MAX && v[tonode] > dist + v[node]){
                    flag = true;
                    break;
                    //v[node] = dist + v[tonode];
                }
            }
        }if(flag) {
            cout<<"negative cycle present"<<endl;
        }else{
            cout<<"negative cycle absent"<<endl;
        }
        for(auto i : v){
            cout<<i<<" ";
        }
    }
    void floydwarshall(int n){
        vector<vector<int> > v(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            v[i][i] = 0;
        }
        for(auto i:adj){
            for(auto j : i.second){
                v[i.first][j.first] = j.second;
            }
        }//int src = 0;src<n;src++
        for(int src = 0;src<n;src++){
            for(int helper = 0;helper <n;helper++){
                for(int dest = 0;dest < n; dest++){
                    v[src][dest] = min(v[src][dest],v[src][helper] + v[helper][dest]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<v[i][j]<<" ";
            }cout<<endl;
        }
    }
    void dfs1(int src,stack<int>& s,unordered_map<int,bool>&vis){
        vis[src] = true;
        for(auto nbr : adj[src]){
            if(!vis[nbr.first]){
                dfs1(nbr.first,s,vis);
            }
        }
        s.push(src);
    }
    void dfs2(int src,unordered_map<int,bool>&vis,unordered_map<int,list<int> >&adjnew){
        vis[src] = true;
        for(auto nbr : adjnew[src]){
            if(!vis[nbr]){
                dfs2(nbr,vis,adjnew);
            }
        }
    }
    void kosaraju(int n){
        stack<int> s;
        unordered_map<int,bool> vis;
        for(int i=0;i<n;i++){
            if(!vis[i])
            dfs1(i,s,vis);
        }
        unordered_map<int,list<int> > adjnew;
        for(auto i:adj){
            for(auto j:i.second){
                adjnew[j.first].push_back(i.first);
            }
        }vis.clear();
        int c = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs2(i,vis,adjnew);
                c++;
            }
            
        }
        cout<<c<<endl;
    }
    void completelyconnected(int n){
        stack<int> st;
        unordered_map<int,bool> vis;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs1(i,st,vis);
            }
        }
        unordered_map<int,list<int> > adjn;
        for(auto i: adj){
            for(auto j:i.second){
                adjn[j.first].push_back(i.first);
            }
        }
        int c=0;
        vis.clear();
        while(!st.empty()){
            if(!vis[st.top()]){
                dfs2(st.top(),vis,adjn);
                c++;
            }
            st.pop();
        }
        cout<<c<<endl;

    }
    
};
int main(){
    Graph g;
    unordered_map<int,bool> vis;
    unordered_map<int,bool> dfsvis;
    unordered_map<int,int> indeg;
    stack<int> s;
    g.addEdge(0,1,1,2);
    g.addEdge(1,2,1,3);
    g.addEdge(2,3,1,2);
    g.addEdge(3,0,1,3);
    g.addEdge(2,4,1,3);
    // g.addEdge(1,6,1,3);
    // g.addEdge(6,4,1,4);
    // //g.addEdge(6,5,1,0);
    // g.addEdge(1,5,1,1);
    // g.addEdge(5,4,1,3);
    // g.topodfs(1,vis,s);
    // g.shortestweightedpath(1,4,s);
    //g.djikstra(1,2);
   // g.bellamford(0,4);
    //g.floydwarshall(4);
    //g.kosaraju(5);
    g.completelyconnected(5);
}