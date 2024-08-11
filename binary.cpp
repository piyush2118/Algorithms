#include<iostream>
using namespace std;
int binser(int arr[],int start,int end,int target){
    int mid=start+(end-start)/2;
    if(target==arr[mid]) return mid;
    else if(target>arr[mid]) return binser(arr,mid+1,end,target);
    else if(target<arr[mid]) return binser(arr,start,mid-1,target);
    else return -1;
}
//first occurence...
int occure(int* arr,int start,int end,int target){
    int mid=(start+end)/2;
    if(*(arr+mid)==target){
        if(binser(arr,start,mid-1,target)==-1) return mid;
        else return binser(arr,start,mid-1,target);
    }
    else if(*(arr+mid)>target) return occure(arr,start,mid-1,target);
    else if(*(arr+mid)<target) return occure(arr,mid+1,end,target);
     else return -1;

}
//peak element
int peak(int arr[],int start,int end){
    int mid=start+(end-start)/2;
    if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]&&mid<end&&mid>start) return arr[mid];
    else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]&&mid<end&&mid>start) return peak(arr,mid,end);
    else if(arr[mid]<arr[mid-1]&&arr[mid]>arr[mid+1]&&mid<end&&mid>start) return peak(arr,start,mid);
    else return -1;
}

int main(){
    int arr[]={4,4,7,11,6};
    //cout<<"occurence at- "<<occure(arr,0,4,6);
    cout<<"peak is-"<<peak(arr,0,4);
    
}