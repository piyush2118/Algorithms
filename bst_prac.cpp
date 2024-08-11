#include<iostream>
using namespace std;
#include<queue>
#include<vector>
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
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data < root->data){
        root->left = create(root->left,data);
    }else{
        root->right = create(root->right,data);
    }
}
node* findtarget(node*& root,int target){
    if(root == NULL){
        return NULL;
    }if(root->data > target){
        node* leftAns = findtarget(root->left,target);
    }else if(root->data == target){
        return root;
    }
    else{
        node* rightAns = findtarget(root->right,target);
    }
}
