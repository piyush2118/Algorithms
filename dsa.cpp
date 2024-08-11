#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    int count=0;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"enter array element"<<endl;
        cin>>arr[i];

    }
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==-1)
            continue;
            if(arr[i]==arr[j]&&arr[j]!=-1){
                arr[j]=-1;
                count++;
            }
        }
        if(arr[i]!=-1)
        cout<<"count of "<<arr[i]<<"is "<<count+1<<endl;
        count=0;
    }

    for(int i=0;i<size;i++){
        
        if(arr[i]!=-1){
            cout<<"arr elements-"<<endl;
            cout<<arr[i]<<endl;
        }
    }
}