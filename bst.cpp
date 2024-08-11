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
node* create(node*& root){
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
    if(data==-1) return NULL;
    root=new node(data);
    create(root->left);
    create(root->right);
    return root;
}
void traverse(node*& root,queue<node*> q){
    node* temp=q.front();
    cout<<temp->data<<" ";
    q.pop();
    if(temp->left!=NULL) q.push(temp->left);
    if(temp->right!=NULL) q.push(temp->right);
    if(q.front()==NULL&&!q.empty()){
        q.pop();q.push(NULL);cout<<endl;
    }
    if(q.empty()) return;
    traverse(q.front(),q);

}
void inorder(node*& root){
    if (root==NULL) return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    
}
void preorder(node*& root){
    if (root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int height(node*& root){
    if(root==NULL) return 0;
    int lefth=height(root->left);
    int righth=height(root->right);
    int ans=max(lefth,righth)+1;
    return ans;
    
}
int diametre(node*& root){
    if(root==NULL) return 0;
    int leftd=diametre(root->left);
    int rightd=diametre(root->right);
    int mid=height(root->left)+height(root->right)+1;
    int ans=max(mid,max(leftd,rightd));
    return ans;

}
bool trav(node*& root1,node*& root2,bool& ans){
    
    if(ans==false) return ans;
    if(root1==NULL||root2==NULL) return NULL;    
    trav(root1->left,root2->left,ans);
    if(ans==false) return false;
    if(root1->data==root2->data) {
        ans=true;cout<<root1->data<<endl;
        
    }
    else{
        ans=false; return ans;
    }
    
    
    trav(root1->right,root2->right,ans);
    return ans;

}
int convert(node*& root){
    if(root==NULL) return 0;
    root->data=convert(root->left)+convert(root->right)+root->data;
    return root->data;
    
}
int count(node*& root){
    if(root==NULL) return 0;
    if(root->left==NULL&&root->right==NULL){
        return 1;
    }
    int c=count(root->left)+count(root->right);
    return c;
}

node* create_bst(node*& root,int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(root->data>data){
        create_bst(root->left,data);
    }
    else create_bst(root->right,data);
    return root;

}
void takeInput(node*& root){
    int data;cin>>data;
    while(data!=-1){
        create_bst(root,data);
        cin>>data;
    }
}
bool search(node*& root,int data){
    if(root==NULL) return false;
    if(root->data==data) return true;
    if(root->data>data) return search(root->left,data);
    else search(root->right,data);
   
}

void deletion(node*& root,int data){
    while(root->data!=data){
        if(data<root->data) root=root->left;
        else root=root->right;
    }
    if(root->left==NULL&&root->right==NULL) root=NULL;
    if(root->left==NULL&&root->right!=NULL){
        root=root->right;
    } 
    if(root->left!=NULL&&root->right==NULL){
        root=root->left;
    } 
    else{

    }
}
int main(){
    node* root1=NULL;
    // node* root2=NULL;
    // queue<node*> q;
    // cout<<"enter values for tree1"<<endl;
    // create(root1);
    // cout<<"enter values for tree2"<<endl;
    // create(root2);
    // bool ans=true;
    // cout<<"ans is "<<trav(root1,root2,ans);
    // q.push(root);
    // q.push(NULL);
    // cout<<endl;
    // cout<<height(root);
    //cout<<diametre(root);
    cout<<"enter data"<<endl;
    takeInput(root1);
    // traverse(root,q);
    cout<<"inorder traversal"<<endl;
    inorder(root1);
    cout<<endl;
    //preorder(root);
    // convert(root1);
    // inorder(root1);
    //cout<<"count= "<<count(root1);
    cout<<search(root1,5);

}