#include <bits/stdc++.h>
using namespace std;
 
struct Process {
    int pid; 
    int arr_t; 
    int bt; 
    int priority;
};

bool compareProcess(Process a,Process b){
    if(a.arr_t!=b.arr_t)
        return a.arr_t<b.arr_t;
    return a.pid<b.pid;
}


void prioritySched(Process p[],int n){
    sort(p,p+n,compareProcess);
    int t=0;
    int tat[n],wt[n];
    int b[n];
    for (int i = 0; i < n; ++i)
    {
        b[i]=p[i].bt;
    }
    int count =0;
    while(count!=n)
    {
        count++;
        int i=0;
        while(b[i]==0){
            i++;
        }
        int mn=-1;
        int index=i;
        if(t<p[i].arr_t){
            t=p[i].arr_t;
        }
        for(int j=i;j<n;j++){

            if(t>=p[j].arr_t&&b[j]!=0){
                if(mn<p[j].priority){
                    mn=p[j].priority;
                    index=j;
                }
            }
            if(j==n-1){
                wt[index]=t-p[index].arr_t;
                t+=p[index].bt;
                b[index]=0;
                tat[index]=t-p[index].arr_t;
            }
            else if(b[j]!=0&&t<p[j].arr_t)
            {
                wt[index]=t-p[index].arr_t;
                t+=p[index].bt;
                b[index]=0;
                tat[index]=t-p[index].arr_t;
                break;
            }
            

        }
    }
    int total_tat=0,total_wt=0;
    cout<<"Process\tAT\tBT\tPriority\tTAT\tWT\n";
    for (int i = 0; i < n; ++i)
    {
        total_tat+=tat[i];
        total_wt+=wt[i];
        cout<<p[i].pid<<"\t"<<p[i].arr_t<<"\t"<<p[i].bt<<"\t"<<p[i].priority<<"\t\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
    }
    cout<<"Average Turnaround time is "<<(float)total_tat/(float)n<<"\n";
    cout<<"Average Waiting time is "<<(float)total_wt/(float)n<<"\n";
}

int main()
{
    Process p[] = { { 1, 1, 6,2 }, { 2, 1, 8,5 },
                    { 3, 2, 7,4 }, { 4, 3, 3 ,12} };
    int n = sizeof(p) / sizeof(p[0]);
 
    prioritySched(p, n);
    return 0;
}