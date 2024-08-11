#include<iostream>
#include<string>
#include<vector>
using namespace std;
//implement n stacks in an array...
//inplement n queues in an array...

// void push_arr(vector<int>&arr,vector<int>&toparr,vector<int>&next_empty,int ele,int m,int&next_free){
//     //m denotes 1 based stack no
//     int index = next_free;
//     arr[index] = ele;
//     next_free = next_empty[index];
//     next_empty[index] = toparr[m-1];
//     toparr[m-1] = index;
    

// }
// int pop_arr(vector<int>&arr,vector<int>&toparr,vector<int>&next_empty,int m,int&next_free){
//     int index = toparr[m-1];
//     toparr[m-1] = next_empty[index];
//     next_empty[index] = next_free;
//     next_free = index;
//     return arr[index];

// }
void push_rear(vector<int>&arr,vector<int>&front,vector<int>&rear,vector<int>&next,int freespot,int k,int ele){
    int index = freespot;
    arr[index] = ele;
    freespot = next[index];
    next[index] = front[k-1];
    front[k-1] = index;
    rear[k-1] =index;
    

}
int main(){
    vector<int>arr(6);
    // vector<int>toparr(3,-1);//3 stacks
    vector<int>front(3,-1);
    vector<int>rear(3,-1);
    vector<int>next = {1,2,3,4,5,-1};
    int freespot = 0;


}