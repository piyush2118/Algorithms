#include<iostream>
#include<vector>
using namespace std;
int main(){
    int width = 15;
    int height = 8;
    int tower = 3;
    vector<int> col(tower+2);
    vector<int> row(tower+2);
    col[0] = -1;
    col[tower+1] = width;
    row[0] = -1;
    row[tower+1] = height;
    for(int i=0;i<tower;i++){
        cin>>row[i+1]>>col[i+1];
    }
    sort(row.begin(),row.end());
    sort(col.begin(),col.end());
    int rowgap = 0,colgap = 0;
    for(int i=0;i<row.size()-1;i++){
        rowgap = max(rowgap,abs(row[i]-row[i+1]-1));
        colgap = max(colgap,abs(col[i]-col[i+1]-1));
        cout<<rowgap<<" "<<colgap<<endl;
    }
    cout<<rowgap*colgap<<endl;
}