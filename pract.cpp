#include<iostream>
#include<vector>
#include<string>
using namespace std;
// bool isSafe(int arr[][4],int newx,int newy,int row,int col,vector<vector<bool> >& v){
//     if(newx >=0 && newy >=0 && newx < row && newy < col && v[newx][newy] == false && arr[newx][newy] == 1  )
//         return true;
//     return false;
// }
// void solve(int arr[][4],int cx,int cy,int row,int col,vector<vector<bool> >& v,string& ans){
//     if(cx == row-1 && cy == col-1){
//         cout<<ans<<endl;
//         return;
//     }
    
//     //up
//     int newx = cx-1;
//     int newy = cy;
//     if(isSafe(arr,newx,newy,row,col,v)){
//         v[newx][newy] = true;
//         ans.push_back('U');
//         solve(arr,newx,newy,row,col,v,ans);
//         //backtrack
//         ans.pop_back();
//         v[newx][newy] = false;
//     }
//     //right
//     newx = cx;
//     newy = cy+1;
//     if(isSafe(arr,newx,newy,row,col,v)){
//         v[newx][newy] = true;
//         ans.push_back('R');
//         solve(arr,newx,newy,row,col,v,ans);
//         //backtrack
//         ans.pop_back();
//         v[newx][newy] = false;
//     }
//     //down
//     newx = cx+1;
//     newy = cy;
//     if(isSafe(arr,newx,newy,row,col,v)){
//         v[newx][newy] = true;
//         ans.push_back('D');
//         solve(arr,newx,newy,row,col,v,ans);
//         //backtrack
//         ans.pop_back();
//         v[newx][newy] = false;
//     }
//     //left
//     newx = cx;
//     newy = cy-1;
//     if(isSafe(arr,newx,newy,row,col,v)){
//         v[newx][newy] = true;
//         ans.push_back('L');
//         solve(arr,newx,newy,row,col,v,ans);
//         //backtrack
//         ans.pop_back();
//         v[newx][newy] = false;
//     }
// }
//all substr of a string
void subst(string s,int index,string out){
    if(index == s.length()){
        cout<<out<<endl;
        return;
    }
    //exclude
    
    //include
    out.push_back(s[index]);
    subst(s,index+1,out);
    out.pop_back();
    subst(s,index+1,out);

}
void permut(string& s,int index){
    if(index == s.length()){
        cout<<s<<endl;
        return;
    }
    for(int j = index;j<s.length();j++){
        swap(s[index],s[j]);
        permut(s,index+1);
        swap(s[index],s[j]);
    }
}
int maxsq(int arr[][4],int i,int j,int row,int col,int& maxi){
    if( i >= row || j >= col){
        return 0;
    }
    int down = 1 + maxsq(arr,i+1,j,row,col,maxi);
    int right = 1 + maxsq(arr,i,j+1,row,col,maxi);
    int diag = 1 + maxsq(arr,i+1,j+1,row,col,maxi);

    
    if(arr[i][j] == 1){
        int ans = 1+min(down,min(diag,right));
        maxi = max(ans,maxi);
        return ans;
    }
    return 0;
}
int main(){
    int arr[4][4] = {{1,0,0,0},
                    {1,1,0,0},
                    {1,1,1,0},
                    {1,1,1,1}};
    // string out = "";
    // string s ="abc";
    // int index = 0;
    // subst(s,index,out);
    // permut(s,index);
    // int cx=0,cy=0;
    int row = 4,col = 4;
    int maxi = INT_MIN;
    int ans = maxsq(arr,0,0,row,col,maxi);
    cout<<ans*ans;
    // vector<vector<bool> > v(row,vector<bool>(col,false));
    // solve(arr,cx,cy,row,col,v,ans);

    
}