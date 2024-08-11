#include<iostream>
#include<stack>
using namespace std;
//queue using stacks...

void get_mid(stack<int>& s,int size){
    if(s.empty()) return ;
    if(s.size()==size/2+1){
        cout<<s.top()<<endl;
        return;
    } 

    int temp=s.top();
    s.pop();

    get_mid(s,size);

    s.push(temp);

}
void insertAtB(stack<int> &s,int ele){
    if(s.empty()){
         
        s.push(ele);
        return;
    }
    int temp=s.top();
    s.pop();
    insertAtB(s,ele);
    s.push(temp);
}
void rev(stack<int>& s){
    if(s.size()==0){
        return;
    }
    
    int temp=s.top();
    s.pop();
    rev(s);
    insertAtB(s,temp);

}
void sorted(stack<int>& s,int x){
    if(s.size()==0){
        s.push(x);
        return;
    }
    if(x<s.top()){
        s.push(x);
        return;
    }
    int t=s.top();
    s.pop();
    sorted(s,x);
    s.push(t);
}
void sortSt(stack<int>& s){
    if(s.size()==0){
        return;
    }
    int temp=s.top();
    s.pop();
    sortSt(s);
    sorted(s,temp);
    
}
int main(){
    stack<int> s;
    int n;
    cout<<"Enter the no of elements in your linked list"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cout<<"enter element"<<endl;
        cin>>ele;
        s.push(ele);
    }
    get_mid(s,s.size());
    //insertAtB(s,5);
    //rev(s);
    sortSt(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}