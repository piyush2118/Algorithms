#include<iostream>
#include<queue>
#include<string>
using namespace std;
void solve(queue<int>& q){
    if(q.empty()) return;
    int temp=q.front();
    q.pop();
    solve(q);
    q.push(temp);
}
void interLeave(queue<int> &q){
        queue<int> q1;
        int size=q.size();
        for(int i=0;i<size/2;i++){
            q1.push(q.front());
            q.pop();
        }
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
            q.push(q.front());
            q.pop();
        }
}
vector<int> slide(vector<int>& v,int k){
    queue<int> q;
    vector<int> ans;
    int n=v.size();
    for(int i=0;i<k;i++){
        if(v[i]<0){
            q.push(i);
        }
    }
    ans.push_back(v[q.front()]);
    for(int i=1;i<n-k+1;i++){
        //i-1 nikla & i+k-1 ghusa window me...
        if(v[i+k-1]<0){
            q.push(i+k-1);
            
            
                
                while(i>q.front() && !q.empty()){
                    q.pop();
                }
                if(q.empty()){
                    ans.push_back(v[i+k-1]);
                    q.push(i+k-1);
                }
                else{
                    ans.push_back(v[q.front()]);
                }
                    
                
                
            
        }
        else{
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                while(i>q.front() && !q.empty()){
                    q.pop();
                }
                if(q.empty()){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(v[q.front()]);
                }
            }
        }
    }
    return ans;
    
}
vector<char> solve(string s){
    int freq[26]={0};
    queue<char> q;
    vector<char> v;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        freq[ch-'a']++;
        if(freq[ch-'a']<=1){
            q.push(ch);
        }
        char chr=q.front();
        while(freq[chr-'a']>1 && !q.empty()){
            q.pop();
            chr=q.front();
        }
        if(q.empty()){
            v.push_back('#');
        }
        else{
            v.push_back(q.front());
        }
    }
    return v;
}
int main(){
    queue<int> q;
    vector<int> v;
    string s="facfdcad";
    int k=3;
    int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int ele;
    //     cout<<"enter element"<<endl;
    //     cin>>ele;
    //     //q.push(ele);
    //     v.push_back(ele);
    // }
    //interLeave(q);
    //solve(q);
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    vector<char> ans=solve(s);
    for(auto i: ans){
        cout<<i<<" ";
    }
}
