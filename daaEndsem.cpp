#include<iostream>
#include<vector>
using namespace std;
//dnc code to find max and min element in an array
pair<int,int> divide(int s,int e,int arr[]){
    if(s == e){
        return make_pair(arr[s],arr[s]);
    }
    else{
        int m = s+(e-s)/2;
        pair<int,int> pl = divide(s,m,arr);
        pair<int,int> pr = divide(m+1,e,arr);
        return make_pair(max(pl.first,pr.first),min(pl.second,pr.second));
    }

}
//pair<max,min>
int control_center(int s,int e,int arr[]){
    pair<int,int> ans = divide(s,e,arr);
    return ans.first-ans.second;
}
int main(){
    int arr[] = {3,2,5,6,2,5,2,1};
    int ans = control_center(0,7,arr);
    cout<<ans<<endl;
}
