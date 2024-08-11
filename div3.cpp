#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<unordered_set>
#include<set>
#include<queue>
#include<string>
using namespace std;
#include<cmath>
//#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int arr[n];
        unordered_map<int,int> mem;
        set<int> st;
        set<int> s;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i]; 
            st.insert(arr[i]);       
            mem[arr[i]]++; 
            maxi = max(maxi,arr[i]);    
        }
        
        int mini = INT_MAX;
        int mex = 0;
        for(int i:st){
            //cout<<i<<endl;
            if(i == mex) {
                mex++;              
            }
            else{
                break;
            }
        }
        if(mex > maxi && maxi != 0){
            cout<<"-1"<<endl;
            continue;
        }
        //cout<<"mex = "<<mex<<endl;
        for(pair<int,int> i:mem){
            
            if(i.first < mex){
                // cout<<i.first<<" "<<i.second<<endl;
                // cout<<mini<<endl;
                mini = min(mini,i.second);
                //cout<<mini<<endl;
            }else{
                st.erase(i.first);
                //mem.erase(i.first);
            }
        }
        int old = 1;
        
        
        if(mini == INT_MAX){
            mini = n;
            cout<<"0"<<endl;
        }
        else if(mini != INT_MAX){
            cout<<mini<<endl;
        }
        else {cout<<n<<endl;}

        while(mini--){
            s = st;
            
            //int ptr = old;
            for(int i=old-1;i<n;i++){
                if(arr[i] < mex){
                    s.erase(arr[i]);
                }
                if(s.empty()){
                    cout<<old<<" "<<i+1<<endl;
                    old = i+2;
                    break;
                }
            }

        }
       


    }
        
}
    
    
