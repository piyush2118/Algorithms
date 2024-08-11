#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<list>
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
        int size = 2*n;
        string b="**";
        string a="##";
        bool flag=true;
        int colcnt=0;
        for(int i=0;i<size;i++){
            
            if(colcnt==2){
                swap(a,b);
                colcnt=0;
            }
            colcnt++;
            for(int c=0;c<size;c+=2){
                if(flag){
                    cout<<a;
                }else{
                    cout<<b;
                }
                flag=!flag;
            }
            // if(i%2==0){
            //     flag=!flag;
            // }
            cout<<endl;
        }
        
    }

    
}