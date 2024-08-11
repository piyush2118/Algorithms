#include<iostream>
using namespace std;
void heapify(int arr[],int size,int in){
    if(in > size ) return;
    int maxi = in;
    int c1 = 2*in;
    int c2 = 2*in+1;
    if(c1<=size && arr[maxi]<arr[c1]){

        maxi = c1;
    }
    if(c2<=size && arr[maxi]<arr[c2]){

        maxi = c2;
    }
    if(maxi != in){
    swap(arr[maxi],arr[in]);
    heapify(arr,size,maxi);
    }
    else return;
}
void heapSort(int arr[],int size){
    while(size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}
void buildHeap(int arr[],int size){
    cout<<"inside buildheap" <<endl;
    for(int i = size/2;i>=1;i--){
        heapify(arr,size,i);
    }
}
int main(){
    int arr[]={-1,3,5,2,4,63,5,2,1};
    int size = 8;
    for(int i=1;i<=8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    buildHeap(arr,size);
    for(int i=1;i<=8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,size);
    for(int i=1;i<=8;i++){
        cout<<arr[i]<<" ";
    }
}