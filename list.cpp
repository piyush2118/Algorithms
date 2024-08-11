#include<iostream>
#include<stack>
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
void print(node* &head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;

        }

}
void insertAthead(node* &head,node* &tail,int data){
    
    if(tail==NULL){
        node* temp=new node(data);
        tail=temp;
        head=temp;
        
    }
    else{
        node* temp=new node(data);
        temp->next=head;
        head=temp;

    }
    
}
void insertAtTail(node* &head,node* &tail,int data){
    
    if(tail==NULL){
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        node* newnode=new node(data);
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
void insertAtPosition(int pos,int data,node*& head,node*& tail){
    if(head==NULL){
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
        return;
    }
    if(pos==1){
        insertAthead(head,tail,data);
        return;
    }
    if(pos>=calLen(head)){
        insertAtTail(head,tail,data);
        return;
    }
    node* newnode=new node(data);
    node* prev=head;
    for(int i=1;i<pos-1;i++){
        prev=prev->next;
    }
    node* curr=prev->next;
    newnode->next=curr;
    prev->next=newnode;
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
node* revK(node* head,int k){
    if(head == NULL) return NULL;
    //reverse k nodes
    node* prev = NULL;
    node* curr = head;
    node* nxt;
    for(int i=0;i<k;i++){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    node* temp = revK(curr,k);
    head->next = temp;
    return prev; 
}
int main(){
    node* head=NULL;
    node* tail=NULL;
    // stack<int> st[5];
     for(int i=0;i<6;i++){
        cout<<"enter data"<<endl;int data;
        cin>>data;
        insertAthead(head,tail,data);
     }
    // }
    // node* temp=head;
    // for(int i=0;i<5;i++){
    //     st->push(temp->data);
    //     temp=temp->next;
    // }
    // bool flag=true;
    // temp=head;
    // for(int i=0;i<5;i++){
        
    //     if(st->top()==temp->data){
    //         temp=temp->next;
    //         st->pop();
    //         continue;
    //     }
    //     else {
    //         flag=false;
    //         cout<<"not a palindrome"<<endl;
    //         break;
    //     }
        
    // }
    // if(flag==true) cout<<"palindrome!!"<<endl;
    // node* temp=head->next;
    // while(temp!=NULL){
    //     temp->data=0;
    //     if(temp->next==NULL){
    //         temp->data=0;
    //         break;
    //     }

    //     else temp=temp->next->next;
    // }
    node* temp = revK(head,2);
    
    print(temp);
    



}