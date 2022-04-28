#include <bits/stdc++.h>
using namespace std;
 
struct Process {
    int pid; 
    int arr_t; 
    int bt; 
};

bool compareProcess(Process a,Process b){
    if(a.arr_t!=b.arr_t)
        return a.arr_t<b.arr_t;
    return a.pid<b.pid;
}


void FCFS(Process p[],int n){
    sort(p,p+n,compareProcess);
    int t=0;
    int tat[n],wt[n];
    for (int i = 0; i < n; ++i)
    {
        if(p[i].arr_t<=t){
            wt[i]=t-p[i].arr_t;
            t+=p[i].bt;
            tat[i]=t-p[i].arr_t;
        }
        else{
            wt[i]=0;
            t=p[i].arr_t+p[i].bt;
            tat[i]=p[i].bt;
        }
    }
    int total_tat=0,total_wt=0;
    cout<<"Process\tAT\tBT\tTAT\tWT\n";
    for (int i = 0; i < n; ++i)
    {
        total_tat+=tat[i];
        total_wt+=wt[i];
        cout<<p[i].pid<<"\t"<<p[i].arr_t<<"\t"<<p[i].bt<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
    }
    cout<<"Average Turnaround time is "<<(float)total_tat/(float)n<<"\n";
    cout<<"Average Waiting time is "<<(float)total_wt/(float)n<<"\n";
}

int main()
{
    Process p[] = { { 1, 1, 6 }, { 2, 1, 8 },
                    { 3, 2, 7 }, { 4, 3, 3 } };
    int n = sizeof(p) / sizeof(p[0]);
 
    FCFS(p, n);
    return 0;
}