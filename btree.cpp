#include<iostream>
#include<queue>
using namespace std;
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
void Lvl(queue<node*>& q){
    node* temp=q.front();
    if(temp==NULL) return;
    cout<<temp->data<<" ";
    if(temp->left!=NULL) q.push(temp->left);
    if(temp->right!=NULL) q.push(temp->right);
    q.pop();

    if(!q.empty() && q.front()==NULL) {
        q.pop();
        
        cout<<endl;
        q.push(NULL);
    }
    Lvl(q);

}
int height(node*& root){
    if(root==NULL) return 0;
    int left_h=1+height(root->left);
    int right_h=1+height(root->right);
    return max(left_h,right_h);
}
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
bool findP(node* root,int val){
    if(root == NULL){
        return false;
    }
    if(root->data == val){
        return true;
    }
    bool p1 = findP(root->left,val);
    bool p2 = findP(root->right,val);

    return (p1 || p2) ;
}
void solve(node*& root,int& nk,int val,int& k,bool flag){
    if(root == NULL){
        return;
    }
    
    if(k==0){
        nk=root->data;
        return;
    }
    if(flag){
        k--;
        return;
    }
    if(root->data == val){
        flag=true;
        k--;
        return;
    }
    solve(root->left,nk,val,k,flag);
    solve(root->right,nk,val,k,flag);
}
int find(node*& root,int val,int& k){
    int nk;
    bool flag=false;
    solve(root,nk,val,k,flag);
    int ans=nk;
    return ans;
    
}
void printLeft(node*& root){
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        return;
    cout<< root->data<<" ";
    if(root->left != NULL){
        printLeft(root->left);
    }
        
    else{
        printLeft(root->right);
    }
        
}
void printRight(node*& root){
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        return;
    
    if(root->right != NULL)
        printRight(root->right);
    else
        printRight(root->left);
    cout<< root->data<<" ";
}
void printLeaf(node*& root){
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    printLeaf(root->left);
    printLeaf(root->right);
}

int main(){
    
    

    node* root=NULL;
    create(root);
    
    printLeft(root);
    printLeaf(root);
    if(root->right!=NULL)
    printRight(root->right);
    else
    printRight(root->left);
   // cout << find(root,val,k);
   // Lvl(q);
    cout<<endl;
    //LeftV(q);
    
    cout<<endl;
    //cout<<height(root);

}