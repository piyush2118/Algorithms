#include<iostream>
using namespace std;
#include<stack>
void solve(stack<int>& s,int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }

    int temp=s.top();
    s.pop();
    solve(s,ele);
    s.push(temp);
}
void revS(stack<int>& s){
    if(s.empty()) return;
    int temp=s.top();
    s.pop();
    revS(s);    
    solve(s,temp);

}
//sort a stack
void crt(stack<int>& s,int ele){
    if(s.empty()) {
        s.push(ele);
        return;
    }
    int temp=s.top();
    if(temp>ele){
        s.push(ele);
        return;
    }
    s.pop();
    crt(s,ele);
    s.push(temp);
}
void sorted(stack<int>& s){
    if(s.empty()) return;
    int temp=s.top();
    s.pop();
    sorted(s);
    crt(s,temp);
}
bool redunt(string s){
    int index=0;
    stack<char> st;
    while(index<s.length()){
        char ch = s[index];
        if(ch=='('){
            st.push(ch);
        }
        else if(ch=='+' || ch=='-' || ch=='/' || ch=='*'){
            st.push(ch);
        }
        else if(ch>=97 && ch<=123){
                index++;
                continue;
        }
        else{
            char topch=st.top();
            
            if(ch == ')' && topch=='('){
                return true;
            }
            else if(st.empty()){
                return true;
            }
            else{
                while(topch!='('){
                    st.pop();
                    topch=st.top();
                }
                st.pop();
            }
        }
        index++;
    }
    if(st.empty()) return false;
    else return true;
}

int main(){
    stack<int> s;
    s.push(-1);
    int arr[]={2,1,5,6,2,3};
    vector<int> v(6);
    for(int i=5;i>=0;i--){
        if(arr[i]>s.top()){
            v[i]=s.top();
            s.push(arr[i]);
            
        }
        else{
            while(arr[i]<s.top()){
                s.pop();
            }
            v[i]=s.top();
            s.push(arr[i]);
        }
    }
    
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    for(auto i: v){
        cout<<i<<" ";
    }
}