#include<iostream>
using namespace std;
#include<string>
bool isSafe(int maze[][4],int cx,int cy,int newx,int newy,vector<vector<bool> >& v,int row,int col){
    if(newx<row && newx>=0 && newy>=0 && newy<col && v[newx][newy]==false && maze[newx][newy]==1){
        return true;
    }
    else
    return false;
}
void solve(int maze[][4],int cx,int cy,int row,int col,vector<vector<bool> >& v,string& output){
    //base case
    if(cx==row-1&&cy==col-1){
        cout<<output<<endl;
        return;
    }
    //up
    int newx=cx-1;
    int newy=cy;
    if(isSafe(maze,cx,cy,newx,newy,v,row,col)){
        
        //mark visited place true
        v[newx][newy]=true;
        output.push_back('u');
        //reccursion call
        solve(maze,newx,newy,row,col,v,output);
        output.pop_back();
        //backtrack
        v[newx][newy]=false;

    }
    //down
    newx=cx+1;
    newy=cy;
    if(isSafe(maze,cx,cy,newx,newy,v,row,col)){
        
        //mark visited place true
        v[newx][newy]=true;
        output.push_back('d');
        //reccursion call
        solve(maze,newx,newy,row,col,v,output);
        output.pop_back();
        //backtrack
        v[newx][newy]=false;

    }
    //right
    newx=cx;
    newy=cy+1;
    if(isSafe(maze,cx,cy,newx,newy,v,row,col)){
        
        //mark visited place true
        v[newx][newy]=true;
        output.push_back('r');
        //reccursion call
        solve(maze,newx,newy,row,col,v,output);
        output.pop_back();
        //backtrack
        v[newx][newy]=false;

    }
    //left
    newx=cx;
    newy=cy-1;
    if(isSafe(maze,cx,cy,newx,newy,v,row,col)){
        
        //mark visited place true
        v[newx][newy]=true;
        output.push_back('l');
        //reccursion call
        solve(maze,newx,newy,row,col,v,output);
        output.pop_back();
        //backtrack
        v[newx][newy]=false;

    }
}

int main(){
    int maze[4][4]={
        {1,0,0,0},
        {1,0,0,0},
        {1,1,1,0},
        {1,1,1,1}

    };
    string output="";
    int row=4,col=4;
    int cx=0,cy=0;
    vector<vector<bool> > v(row,vector<bool>(col,false));
    if(maze[cx][cy]==0) cout<<"not possible"<<endl;
    else{
        v[cx][cy] = true;
        solve(maze,cx,cy,row,col,v,output);
    }
}