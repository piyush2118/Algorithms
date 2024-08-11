void tsdfs(int src,stack<int>&s,unordered_map<int,bool>&vis){
        vis[src] = true;
        for(auto i: adj[src]){
            if(!vis[i.first]){
                tsdfs(i.first,s,vis);
            }
        }
        s.push(src);
    }