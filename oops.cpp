#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insert(node*& head,node*& tail,int data){
    if(head==NULL){
        node* newNode=new node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    node* newNode=new node(data);
    tail->next=newNode;
    tail=newNode;

}
void pop(node*& head,node*& tail){
    node* temp=head;
    while(temp->next!=tail){
        temp=temp->next;

    }
    temp->next=NULL;
    tail=temp;
}
void display(node*& head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int peek(node*& tail){
    return tail->data;
}
int main(){
    
    node* head=NULL;
    node* tail=NULL;
    insert(head,tail,5);
    insert(head,tail,6);
    insert(head,tail,7);
    display(head);
    pop(head,tail);
    display(head);

}