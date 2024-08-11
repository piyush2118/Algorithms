#include<iostream>
using namespace std;
class node{
    public:
    int data;
    int row;
    int col;
    node* next;
    
    node(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
        this->next=NULL;
    }
     
    
    
};
void print(node* &head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" "<<temp->row<<" "<<temp->col<<endl;
            temp=temp->next;

        }

}

void insert(node* &head,node* &tail,int data,int row,int col){
    node* newnode=new node(data,row,col);
    if(tail==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
    
    
}
int calLen(node*& head){
    node* temp=head;int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

void deleteNode(int pos,node*& head,node*& tail){
    if(pos==1){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp; 
        return;
    }
    if(pos>=calLen(head)){
        node* prev=head;
        for(int i=1;i<calLen(head)-1;i++){
            prev=prev->next;
        }
        prev->next=NULL;
        tail=prev;
        return;
    }
    node* prev=head;
    for(int i=1;i<pos-1;i++){
        prev=prev->next;}
    node* curr=prev->next;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    

}
int main(){
    int arr[][3]={{0,0,1},
                    {2,0,0},
                    {0,3,0}};
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]!=0){
                insert(head,tail,arr[i][j],i,j);
            }
        }
    }
    print(head);
}