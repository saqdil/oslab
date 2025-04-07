#include <stdio.h>
struct process
{
    int id;
    int burst;
    int arrival;
    int wait;
    int turnaround;
};
int main()
{
    int n,i,j;
    struct process p[10];
    float total_turnaround=0,total_wait=0;
    printf("Enter the number of process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i].id=i+1;
        printf("Enter the Arrival and burst time of Pocess:%d",i+1);
        scanf("%d %d",&p[i].arrival,&p[i].burst);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].burst>p[j].burst)
            {
                struct process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    int current=0;
    for(i=0;i<n;i++)
    {
        if(current<p[i].arrival)
        {
            current=p[i].arrival;
        }
        p[i].wait=current-p[i].arrival;
        p[i].turnaround=p[i].wait+p[i].burst;
        printf(" P %d |",p[i].id);
        total_turnaround+=p[i].turnaround;
        total_wait+=p[i].wait;
        current+=p[i].burst;
    }
    current=0;
    printf("\n0");
    for(i=0;i<n;i++)
    {
        if(current<p[i].arrival)
        {
            current=p[i].arrival;
        }
        current+=p[i].burst;
        printf("    %d",current);
    }
    printf("\nProcessNo\tBurst\t arrival\twait\tTurnaround");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].burst,p[i].arrival,p[i].wait,p[i].turnaround);
    }
    printf("Average waiting time=%.2f",total_wait/n);
    printf("Average turnaround time=%.2f",total_turnaround/n);

}
