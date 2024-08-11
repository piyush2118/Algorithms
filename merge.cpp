#include<iostream>
using namespace std;
void merge(int arr[],int s,int e,int mid){

    int l1 = mid - s + 1;
    int l2 = e-mid;
    int* left = new int[l1];
    int* right = new int[l2];
    int i = 0;int t=s;
    for(;i<l1;i++){
        left[i] = arr[t++];
    }for(;i<l1 + l2;i++){
        right[i-l1] = arr[t++];
    }
    int l=0,r=0,k=s;
    while(l < l1  && r < l2 ){
        if(left[l] < right[r]){
            arr[k++] = left[l++];
        }else{
            arr[k++] = right[r++];
        }
    }
    while(l < l1 ){
        arr[k++] = left[l++];
    }while(r < l2 ){
        arr[k++] = right[r++];
    }
    // delete[] left;
    // delete[] right;
}
void mergesort(int arr[],int s,int e){
    if(s >= e){
        return;
    }
    int mid= s + (e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e,mid);
}
int quick(int arr[],int s,int e){
    // if(s > e) return 0;
    int p = s;
    //s++;
    while(s <= e){
        if(arr[e] < arr[p] && arr[s] > arr[p]){
            swap(arr[s],arr[e]);
            s++;e--;
        }else if(arr[e] > arr[p]) e--;
        else if(arr[s] <= arr[p]) s++;
    }swap(arr[e],arr[p]);
    return e;
}
void quicksort(int arr[],int s,int e){
    if(s > e) return;

    int x = quick(arr,s,e);
    quicksort(arr,s,x-1);
    quicksort(arr,x+1,e);
}
int quickselect(int arr[],int s,int e,int k){
    if(s > e) return 0;

    int x = quick(arr,s,e);
    if(x > k-1)
    return quickselect(arr,s,x-1,k);
    else if(x < k-1)
    return quickselect(arr,x+1,e,k);
    else
    return x;
}
int main(){
    int arr[8] = {3,2,5,-1,8,5,0,24};
    int n = 8;
    int s = 0;int e = n-1;
    cout << arr[quickselect(arr,s,e,4)];
    // for(int i=0;i<n;i++){
    //     cout<<arr[i] << " ";
    // }
}