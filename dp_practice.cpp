#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//#define int long long 
//coin change - find min coin to amount---
int solve(vector<int>&wt,vector<int>&val,int cap,int index){
    if(cap == 0 || index == wt.size()){
        return 0;
    }
    
    
}
signed main(){
    vector<int> val(3);
    vector<int> wt(3);
    wt[0] = 1;
    wt[1] = 4;
    wt[2] = 5;
    val[0] = 3;
    val[1] = 1;
    val[2] = 2;
    int cap = 4;
    int index = 0;
    int ans = solve(wt,val,cap,index);
    cout<<ans<<"\n";
}