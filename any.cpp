#include<iostream>
#include<map>
#include<queue>
//kth greatest element in a vector...
using namespace std;
#include<vector>
int solve(int arr[],int size,int amt){
    if(amt == 0) return 0;
    if(amt <0) return INT_MAX;
    int mini = INT_MAX;
    int ans;
    for(int i=0;i<size;i++){
        int recAns = solve(arr,size,amt - arr[i]);
        if(recAns != INT_MAX){
            ans = 1 + recAns;
        }
        mini = min(ans,mini);
    }
    return mini;
}
int knapsack(int wt[],int val[],int cap,int size,int index,vector<vector<int> >& dp){
    if(cap == 0) return 0;
    if(index == size) return 0;
    if(dp[cap][index] != -1) return dp[cap][index];
    
        int inc = 0;
        if(wt[index] <= cap){
            inc = val[index] + knapsack(wt,val,cap-wt[index],size,index+1,dp);
        }
        int exc = knapsack(wt,val,cap,size,index+1,dp);
        dp[cap][index] = max(inc,exc);

    
    return dp[cap][index];
}
int bottomsUp(int wt[],int val[],int cap,int size){
    vector<vector<int> > dp(cap+1,vector<int>(size+1,0));
    for(int i=0;i<=cap;i++){
        for(int j=size-1;j>=0;j--){
            int inc = 0;
            if(wt[j] <= i){
                inc = val[j] + dp[i-wt[j]][j+1];
            }
            int exc = dp[i][j+1];
            dp[i][j] = max(inc,exc);
        }
    }
    return dp[cap][0];
}

int main(){
    // int k=9;
    // int arr[] = {4,2,4,6,1,3,8,0,9};
    // int n = 9;
    // priority_queue< int,vector<int>,greater<int> > pq;
    // for(int i=0;i<k;i++){
    //     pq.push(arr[i]);
    // }
    // for(int i=k;i<n;i++){
    //     if(arr[i] > pq.top()){
    //         pq.pop();
    //         pq.push(arr[i]);
    //     }

    // }
    // cout<<pq.top()<<endl;
    // int arr[] = {1,2,5};
    // cout<<solve(arr,3,11);
    
    int wt[] = {1,4,5};
    int val[] = {3,1,2};
    int size = 3;
    int cap = 3;
    // vector<vector<int> > dp(cap+1,vector<int>(size+1,-1));
	// cout<<knapsack(wt,val,cap,size,0,dp);
    cout<<bottomsUp(wt,val,cap,size);
}