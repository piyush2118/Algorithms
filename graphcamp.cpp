#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<map>
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
    // void shortesunweightedgraph(int n){
    //     queue<int>q;
    //     vector<int> parent;
    //     unordered_map<int,bool> vis;
    //     parent[0] = -1;

    // }
};
void bfstraversal(int n,int m,vector<vector<char> >&arr,
                    map<pair<int,int>,bool> &vis,
                    pair<int,int> src);
int main() {
    
  
  
    int n,m;
    cin>>n>>m;
    vector<vector<char> > arr(n,vector<char>(m));
    
    
    map<pair<int,int>,bool >vis;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>arr[i][j];
        vis[make_pair(i,j)] = false;
      }
    }
    
    int ans = 0;
    for(int row=0;row<n;row++){
      for(int col=0;col<m;col++){
        
        if(arr[row][col] == '.' && vis[make_pair(row,col)] == false){
          
          ans++;
          bfstraversal(n,m,arr,vis,make_pair(row,col));
        }
      }
    }
    cout<<ans<<endl;
    

  
  
  

}
void bfstraversal(int n,int m,vector<vector<char> >&arr,
                    map<pair<int,int>,bool> &vis,
                    pair<int,int> src)
  {
    queue<pair<int,int> >q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
      pair<int,int> fnode = q.front();
      
      
      q.pop();
      int cx = fnode.first;
      int cy = fnode.second;
      // cout<<cx<<" "<<cy<<endl;
      int dx[] = {-1,0,0,1};
      int dy[] = {0,-1,1,0};
      for(int i=0;i<4;i++){
        int newx = cx + dx[i];
        int newy = cy + dy[i];
        if(newx >= 0 && newx < n && newy >= 0 && newy < m
        && arr[newx][newy] == '.' && vis[make_pair(newx,newy)] == false){
          // cout<<newx<<" "<<newy<<endl;
          
          vis[make_pair(newx,newy)] = true;
          q.push(make_pair(newx,newy));
          
        }
      }
    }
  }
  