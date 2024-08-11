#include<iostream>
using namespace std;
//queue using stacks...
class stk{
    public:
    int top;
    int* arr;
    int size;
    stk(int size){
        this->top=-1;
        this->size=size;
        arr=new int[size];
    }
    void push(int data){
        //cout<<"-2"<<endl;
        if(top==size-1){
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=data;
        //cout<<"4"<<endl;
    }
    void pop(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return;
        }
        top--;

    }
    void display(){
        for(int i=0;i<=top;i++){
            cout<<*(arr+i)<<" ";
        }
        cout<<endl;
    }
    int isempty(){
        //cout<<"-1"<<endl;
        if(top==-1) return 1;
        return 0;
    }
    int peek(){
        return arr[top];
    }

};
void que_push(stk* s1,int data){
    s1->push(data);
}
void que_pop(stk* s1,stk* s2){
    while(s1->top>0){
        s2->push(s1->peek());
        s1->pop();
    }
    s1->pop();
    while(s2->isempty()==0){
        s1->push(s2->peek());
        s2->pop();
    }
}
void que_display(stk* s1){
    s1->display();
}
int main(){
    int size; cout<<"enter size: ";cin>>size;cout<<endl;
    stk* s1=new stk(size);
    stk* s2=new stk(size);
    que_push(s1,5);
    que_push(s1,4);
    que_push(s1,4);
    que_push(s1,3);
    que_display(s1);
    que_pop(s1,s2);
    que_pop(s1,s2);
    que_display(s1);


}