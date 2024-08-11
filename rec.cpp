#include<iostream>
using namespace std;
class employee{
    public:
    int salary;
    int advance;
    float hours;
 float req_hrs;
 employee(int salary,int advance,float hours,float req_hrs){
    this->salary=salary;
    this->advance=advance;
    this->hours=hours;
    this->req_hrs=req_hrs;
 }


};
double cal_sal(int salary,int advance,float hours,float req_hrs){
   employee* x=new employee(salary,advance,hours,req_hrs); 
   float days=x->hours/x->req_hrs;
   float req_days; cout<<"enter the no of working days in this month: ";
   cin>>req_days;
   float due=days-req_days;
   float sal_day=x->salary/req_days;
   double net=x->salary+due*sal_day-x->advance;
    return net;
}
int main(){
    int salary;int advance;float hours; float req_hrs;
    cout<<"enter the salary of the employee"<<endl;
    cin>>salary;
    cout<<"enter the advance of the employee"<<endl;
    cin>>advance;
    cout<<"enter the total no of hours worked by the employee"<<endl;
    cin>>hours;
    cout<<"enter the required no of hours per day by the employee"<<endl;
    cin>>req_hrs;
    double y=cal_sal(salary,advance,hours,req_hrs);
    cout<<"salary of employee: "<<y<<endl;
    return 0;

}