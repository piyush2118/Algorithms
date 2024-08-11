#include<iostream>
using namespace std;
class cque{
    public:
    int* arr;
    int front;
    int rear;
    int size;
    cque(int size){
        this->size=size;
        arr= new int[size];
        front=-1;
        rear=-1;
    }
    void push(int data){
        if(front-rear==size-1||front-rear==1){
            cout<<"q full"<<endl;

        }
        else if(front == -1){
            ++rear;++front;
            arr[rear]=data;
        }
        else if(rear==size-1&&front!=0){
            rear=0;
            arr[rear]=data;
        }
        else{
            arr[++rear]=data;
        }
    }
    void pop(){
        if(front==-1){
            cout<<"q empty"<<endl;
        }
        else if(front!=size-1){
            arr[front++]=-1;
        }
        else if(front==size-1&&front!=rear){
            arr[front]=-1;
            front=0;
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
    }
    void display(){
        if(front<=rear){
            for(int i=front ;i<=rear ;i++){
                cout<<"que ele: "<<arr[i]<<endl;
        }
        }
        else{
            for(int i=front ;i< size ;i++){
                cout<<"que ele: "<<arr[i]<<endl;
            }
            for(int i=0 ;i<=rear ;i++){
                cout<<"que ele: "<<arr[i]<<endl;
            }
        }
    }

};
int main(){
    cque q=cque(4);
    q.push(5);
    q.push(3);
    q.pop();
    q.push(3);
    q.push(32);
    q.push(4);
    q.push(6);
    q.display();
}