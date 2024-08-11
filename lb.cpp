#include<iostream>
using namespace std;

void enque(int arr[],int* front,int *rear,int ele){
    if(*rear==sizeof(arr)+1)
    cout<<"queue full"<<endl;
    else{
        arr[*front]=ele;
        *rear=*rear+1;
    }
   
}
 void pop(int arr[],int* front,int *rear){
        if(*rear==*front)
        cout<<"queue empty"<<endl;
        else{
            arr[*front]=-1;
            *front=*front+1;
            if(*front==*rear){
                *front=0;
                *rear=0;
            }
        }
    }

void display(int arr[],int* front,int *rear){
    for(int i=*front;i<*rear-*front;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int front=0;int rear=0;
    enque(arr,&front,&rear,5);
    display(arr,&front,&rear);
    cout<<arr[0]<<endl;
    cout<<sizeof(arr)<<endl;
    for(int i=0;i<sizeof(arr)/4;i++){
        cout<<arr[i]<<endl;
    }
}