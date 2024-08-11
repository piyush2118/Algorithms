#include<iostream>
using namespace std;
class q{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    q(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    void push(int data){
        if(rear==size-1)cout<<"q full"<<endl;
        if(rear==-1){
            rear=0;front=0;arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;

        }
    }
    void pop(){
        if(front ==-1)cout<<"q empty"<<endl;
        if(front==rear){
            front=-1;rear=-1;
        }
        else
        front++;
    }
    void display(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int peek(){
        return arr[front];
    }
};
void stk_push(q* q1,int data){
    q1->push(data);
}
void stk_pop(q* q1,q* q2){
    int i=0;
    while(i<(q1->rear)){
        q2->push(q1->peek());
        q1->pop();
        i++;
    }
    q1->pop();
    while(q2->rear!=-1){
        q1->push(q2->peek());
        q2->pop();
    }
}
void display(q* q1){
    q1->display();
}
int main(){
    q* q1=new q(5);
    q* q2=new q(5);
    stk_push(q1,5);
    stk_push(q1,4);
    stk_push(q1,4);
    stk_push(q1,3);
    display(q1);

    stk_pop(q1,q2);
    display(q1);
    stk_pop(q1,q2);
    
    display(q1);
}