#include <iostream>

using namespace std;
void trans(int arr[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<=i ;j++){
            int t=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=t;
        }
    }
}
void display(int arr[3][3]){
    for(int i=0;i<3;i++){
        cout<<endl;
        for(int j=0;j<3 ;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}
int main(){
   int arr[][3]={{1,2,3},
                {4,5,6},
                {7,8,9}};
    
    trans(arr);
    display(arr);
}      