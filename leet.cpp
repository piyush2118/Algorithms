#include<iostream>
using namespace std;
#include<string>
int main(){
    int h=130,l=110;
    vector<bool> sieve(h-l+1,true);
    vector<bool> s(sqrt(h)+1,true);
    s[0]=s[1]=false;
    for(int i=2;i*i<=sqrt(h);i++){
        if(s[i]==true){
            int j = i*i;
            while(j<=sqrt(h)){
                s[j]=false;
                j+=i;
            }
        }
    }int count=0;
    // for(int i=0;i<=sqrt(h);i++){
    //     if(s[i]){
    //         count++;
    //     }
    // }

    for(int i=2;i<=sqrt(h);i++){
        if(s[i]){
            int z;
            z=max((l/i)*i,i*i);
            if(z<l) z+=i;
            //cout<<z<<endl;
            while(z<=h){
                sieve[z-l]=false;
                z+=i;
            }

        }
    }
    for(int i=0;i<sieve.size();i++){
        if(sieve[i]){
            cout<<i<<endl;
            count++;
        }
    }
    cout<<count;


}
    
    
    
        

