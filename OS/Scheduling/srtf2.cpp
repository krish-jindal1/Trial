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


void SJF(Process p[],int n){
    sort(p,p+n,compareProcess);
    int t=0;
    int b[n];
    for (int i = 0; i < n; ++i)
    {
        b[i]=p[i].bt;
    }



    int tat[n],wt[n];
    int count =0;



    while(count!=n)
    {
        int i=0,mn=INT_MAX,index;
        while(b[i]==0){
            i++;
        }
        if(t<p[i].arr_t){
            t=p[i].arr_t;
        }


        for(int j=i;j<n;j++)
        {
            if(t>=p[j].arr_t&&b[j]!=0){
                if(mn>p[j].bt){
                    mn=p[j].bt;
                    index=j;
                }
            }

            if(j==n-1){
                b[index]--;
                t++;
                if(b[index]==0){
                    count++;
                    tat[index]=t-p[index].arr_t;
                    wt[index]=tat[index]-p[index].bt;
                }

            }

            else if(b[j]!=0&&t<p[j].arr_t)
            {
               b[index]--;
                t++;
                if(b[index]==0){
                    count++;
                    tat[index]=t-p[index].arr_t;
                    wt[index]=tat[index]-p[index].bt;
                }
                break;
            }
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
    cout<<"Average Turnaround time is "<<total_tat/n<<"\n";
    cout<<"Average Waiting time is "<<total_wt/n<<"\n";
}

int main()
{
    Process p[] = { { 1, 1, 6 }, { 2, 1, 8 },
                    { 3, 2, 7 }, { 4, 3, 3 } };
    int n = sizeof(p) / sizeof(p[0]);
 
    SJF(p, n);
    return 0;
}