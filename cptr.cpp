#include<iostream>
using namespace std;
int merge(int arr[],int s,int e){
    int count=0;
    int mid=s+(e-s)/2;
    int i=0;int j=0;
    int pos=s;
    int index1=mid-s+1;
    int index2=e-mid;
    int* left=new int[index1];
    int* right=new int[index2];
    for(int z=0;z<index1;z++){
        left[z]=arr[pos];
        pos++;
    }pos=mid+1;
    for(int z=0;z<index2;z++){
        right[z]=arr[pos];
        pos++;
    }
    pos=s;
    while(i<index1&&j<index2){
        if(left[i]<=right[j]){
            arr[pos]=left[i++];
            
            
            
        }
        else{
            arr[pos]=right[j++];
            count+=mid-i+1;
            
            
        }
        pos++;
    }
    
    while(j<index2){
        arr[pos]=right[j];
        j++;pos++;
    }
    while(i<index1){
        arr[pos]=left[i];
        i++;pos++;
    }
    delete[] left;
    delete[] right;
    return count;
}
int mergeSort(int arr[],int s,int e){
    if(s>=e) return 0;
    int mid=s+(e-s)/2;
    int c=0;
    c+=mergeSort(arr,s,mid);
    c+=mergeSort(arr,mid+1,e);
    
    c+=merge(arr,s,e);
    return c;
}
int main(){
    int arr[]={2,1,3,1,2};
    int s=0,e=4;
    cout<< mergeSort(arr,s,e)<<endl;

    for(int i=0;i<=4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}