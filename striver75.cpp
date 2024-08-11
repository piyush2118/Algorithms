#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,0,2,1,0,0,1,2};
    int n = sizeof(arr)/4;
    int i=0,j=n-1,k=0;
    //k remains at 0th index i and j are compared
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    while(i<=j){
        if(arr[i] > arr[j]){
            swap(arr[i],arr[j]);
            
            if(arr[k] > arr[i]){
                swap(arr[k],arr[i]);
                k++;
            }
            i++;
        }
        else if(arr[i] < arr[j]){
            
            if(arr[k] > arr[i]){
                swap(arr[k],arr[i]);
                k++;
            }
            i++;
        }
        else{
            if(arr[k] > arr[i]){
                swap(arr[k],arr[i]);
                k++;
            }
            i++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}