#include<iostream>
using namespace std;
class Queue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }
    void push(int data){
        if(rear==this->size+1)cout<<"q full"<<endl;
        else{
            arr[rear++]=data;

        }
    }
    void pop(){
        if(front ==rear)cout<<"q empty"<<endl;
        else
        arr[front++]=-1;
    }
    void display(){
        for(int i=front;i<rear;i++){
            cout<<"Q element: "<<arr[i]<<endl;
        }
    }
};
int main(){
    Queue q=Queue(5);
    q.push(2);
    q.push(5);
    q.push(10);
    q.pop();
    q.display();
    return 0;

}