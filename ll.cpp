#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
        this->data=0;
        this->next=NULL;
    }
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(node*& head,node*& tail,int data){
    if(head==NULL){
        node* newNode=new node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    node* newNode=new node(data);
    newNode->next=head;
    head=newNode;
}
void insertAtTail(node*& head,node*& tail,int data){
    if(tail==NULL){
        node* newNode=new node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    node* newNode=new node(data);
    tail->next=newNode;
    tail=newNode;

}
void print(node*& head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int len(node*& head){
    node* temp=head;int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertAnywhere(int pos,int data,node*& head,node*& tail){
    if(pos==1){
        insertAtHead(head,tail,data);
        return;
    }
    if(pos==len(head)){
        insertAtTail(head,tail,data);
        return;
    }
    node* prev=head;
    for(int i=1;i<pos-1;i++){
        prev=prev->next;
    }
    node* curr=prev->next;
    node* newNode=new node(data);
    newNode->next=curr;
    prev->next=newNode;
}
void deleteNode(int pos,node*& head,node*& tail){
    if(pos==1){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        return;
    }
    if(pos==len(head)){
        node* temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        return;

    }
    node* prev=head;
    for(int i=1;i<pos-1;i++){
            prev=prev->next;
        }
    node* curr=prev->next;
    prev->next=curr->next;
    delete(curr);
}
void rev(node*& prev,node*& curr){
    if(curr==NULL) {
        print(prev);
        return;
    }
    node* nxt=curr->next;
    curr->next=prev;
    
    rev(curr,nxt);
}
node* getM(node*& head){
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node* revK(node*& head,int k){
    if(head==NULL) return NULL;
    node* prev=NULL;
    node* curr=head;
    int index=0;
    node* temp;
    while(index<k){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        index++;
    }
    node* ans=revK(temp,k);
    head->next=ans;
    return prev;

}

int main(){
    node* head = NULL;
    node* tail=NULL;
    int n;
    cout<<"Enter the no of elements in your linked list"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cout<<"enter element"<<endl;
        cin>>ele;
        insertAtTail(head,tail,ele);
    }
    print(head);
    cout<<endl;
    //reversing the linked list
    
    node* prev=NULL;
    node* curr=head;
    // node* nxt=head->next;
    // while(curr!=NULL){
    //    curr->next=prev;
    //     prev=curr;
    //     curr=nxt;
    //     if(nxt!=NULL)
    //     nxt=nxt->next;
    // }
    // rev(prev,curr);
    // cout<<"middle is "<<getM(head)->data<<endl;
    node* ans=revK(head,2);
    print(ans);
    
}
   