#include<iostream>
using namespace std;
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
int main(){
    int size;cout<<"enter the number of elements you want to enter: ";
    cin>>size;cout<<endl;
    stk* s1=new stk(size);
    stk* s2=new stk(size);
    for(int i=0;i<size;i++){
        //cout<<"0"<<endl;
        int ele;
        cout<<"enter your element: ";cin>>ele;
        if(s1->isempty()==1){
            s1->push(ele);
            //cout<<"4"<<endl;
        }
        
        else{
            //cout<<"-3"<<endl;
            if(ele<s1->peek()){
                //cout<<"1"<<endl;
                s1->push(ele);
            }
            else{
                while(s1->isempty()==0&&ele>s1->peek()){
                   // cout<<"2"<<endl;
                    s2->push(s1->peek());
                    s1->pop();
                }
                s1->push(ele);
                while(s2->isempty()==0){
                    //cout<<"3"<<endl;
                    s1->push(s2->peek());
                    s2->pop();
                }
            }
        }
    }
    s1->display();
}
