#include<stdio.h>
//#include<conio.h>
//fcfs
void fcfs(int n,int bt[n],int p[n])
{
int wt[20], tat[20], i, k, temp;
float wtavg, tatavg;

for(i=0;i<n;i++){
for(k=i+1;k<n;k++){
if(bt[i]>bt[k])
{
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=p[i];
p[i]=p[k];
p[k]=temp;
}
}}
wt[0] = wtavg = 0;
tat[0] = tatavg = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] +bt[i-1];
tat[i] = tat[i-1] +bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
for(i=0;i<n;i++)
{
printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);}
printf("\nAverage Waiting Time -- %f", wtavg/n);
printf("\nAverage Turnaround Time -- %f", tatavg/n);

}
//shortest job first
void sjf(int n,int bt[n],int p[n]){
int  wt[20], tat[20], i, k, temp;
float wtavg, tatavg;

for(i=0;i<n;i++){
for(k=i+1;k<n;k++){
if(bt[i]>bt[k])
{
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=p[i];
p[i]=p[k];
p[k]=temp;
}}}
wt[0] = wtavg = 0;
tat[0] = tatavg = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] +bt[i-1];
tat[i] = tat[i-1] +bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
for(i=0;i<n;i++)
{
printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
printf("\nAverage Waiting Time -- %f", wtavg/n);
printf("\nAverage Turnaround Time -- %f", tatavg/n);
}
}
//priority
void priority(int n,int bt[n],int p[n]){
    int  pri[n],wt[20],tat[20],i, k, temp;
float wtavg, tatavg;

// printf("Enter the number of processes --- ");
// scanf("%d",&n);
for(i=0;i<n;i++)
{
//p[i] = i;
printf("Enter the Priority of Process %d --- ",i);
scanf("%d", &pri[i]);
}
for(i=0;i<n;i++){
for(k=i+1;k<n;k++){
if(pri[i] > pri[k])
{
temp=p[i];
p[i]=p[k]; //swap(p[i],p[k])
p[k]=temp;
temp=bt[i];
bt[i]=bt[k]; //swap(bt[i],bt[k])
bt[k]=temp;
temp=pri[i];
pri[i]=pri[k]; //swap(pri[i],pri[k])
pri[k]=temp;
}}}
wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];

for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<n;i++){
printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],pri[i],bt[i],wt[i],tat[i]);}
printf("\nAverage Waiting Time is --- %f",wtavg/n);
printf("\nAverage Turnaround Time is --- %f",tatavg/n);
}
//round robin
void roundrobin(int n,int bu[n]){
    int i,j,wa[10],tat[10],t,ct[10],max;
float awt=0,att=0,temp=0;

for(i=0;i<n;i++)
{

ct[i]=bu[i];
}
printf("\nEnter the size of time slice -- ");
scanf("%d",&t);
max=bu[0];
for(i=1;i<n;i++){
if(max<bu[i])
    max=bu[i];
}
for(j=0;j<(max/t)+1;j++){
for(i=0;i<n;i++){
if(bu[i]!=0){
if(bu[i]<=t)
{
tat[i]=temp+bu[i];
temp=temp+bu[i];
bu[i]=0;
}
else
{
bu[i]=bu[i]-t;
temp=temp+t;
}
}}}
for(i=0;i<n;i++)
{
wa[i]=tat[i]-ct[i];
att+=tat[i];
awt+=wa[i];
}
printf("\nThe Average Turnaround time is -- %f",att/n);
printf("\nThe Average Waiting time is -- %f ",awt/n);
printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
for(i=0;i<n;i++){
printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],wa[i],tat[i]);
}
}

int main(){
    int n;
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    int bt[n],p[n];
    
    for(int i=0;i<n;i++)
    {
    p[i]=i;
    printf("Enter Burst Time for Process %d -- ", i);
    scanf("%d", &bt[i]);
    }
    int ch;
        printf("Press 1 for FCFS ");
        printf("Press 2 for SJF ");
        printf("Press 3 for Round Robin- ");
        printf("Press 4 for Priority Scheduling- ");

    printf("Enter choice of CPU Scheduling Algorithm: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        fcfs(n,bt,p);
        break;
        case 2:
        sjf(n,bt,p);
        break;
        case 3:
        roundrobin(n,bt);
        break;
        case 4:
        priority(n,bt,p);
        break;
        default: 
        printf("wrong option\n");

        break;
    }
    

}