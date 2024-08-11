#include<iostream>
using namespace std;
#include<queue>
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* create(node*& root,int data){
    
    
    if(root==NULL){
        
        return (new node(data));
    }
    
    
    if(data > root->data){
        
        root->right = create(root->right,data);
    }
        
    else{
        
        root->left = create(root->left,data);
    }
    return root;
        
}
void createTree(node*& root){
    int data;
    cout<<"enter data"<<endl;
    cin>>data;

    while(data!=-1){
        root = create(root,data);
        cout<<"enter data"<<endl;
        cin>>data;

    }
}
void preOrder(node*& root){
    if(root == NULL)
        return;
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}
bool search(node*& root, int target , bool flag){
    if(root==NULL)
        return false;
    if(root->data == target){
        flag=true ;
        return true;
    }
        
    if(target > root->data)
        flag = search(root->right,target,flag);
    else
        flag = search(root->left,target,flag);
    return flag;
    
}
node* CreateinOrder(node*& root,int arr[],int s,int e){
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    node* newNode = new node(arr[mid]);
    root = newNode;
    root->left = CreateinOrder(root->left,arr,s,mid-1);
    root->right = CreateinOrder(root->right,arr,mid+1,e);
    return root;
}
int main(){
    node* root = NULL;
    //createTree(root);
    int arr[] = {10,20,30,40,50,60,70};
    int s=0;int e=6;
    root = CreateinOrder(root,arr,s,e);
    preOrder(root);
    // bool flag=false;
    // cout<<endl;
    // cout<< search(root,0,flag);
}