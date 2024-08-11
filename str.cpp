#include<iostream>
using namespace std;
#include<stack>


int main(){
   
    int arr[]={3,1,2,1};
    stack<int> st;
    st.push(-1);
    int arr1[4];
    for(int i=3;i>=0;i--){
        if(arr[i]<st.top()){
            while(arr[i]<st.top()){
                st.pop();
            }
            arr1[i]=st.top();
            st.push(arr[i]);
        }
        else{
            arr1[i]=st.top();
            st.push(arr[i]);
        }
    }
    for(int j=0;j<4;j++){
        cout<<arr1[j]<<" ";
    }
    
    
    

}