#include <stdio.h>
struct Process
{
    int id,bt,tbt,wt,tat;
}p[20];
int main()
{
    int i,n,tq;
    int x,y;
    printf("Enter the number of Process:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i].id=i+1;
        printf("Enter the process burst time of %d ",i+1);
        scanf("%d",&p[i].bt);
        p[i].tbt=p[i].bt;
    }
    printf("enter the time quanatm ");
    scanf("%d",&tq);
    x=0;
    y=0;
    i=0;
    while(1)
    {
        if(p[i].bt>0)
        {
            if(p[i].bt>tq)
            {
                p[i].bt-=tq;
                x+=tq;
            }
            else
            {
                x+=p[i].bt;
                p[i].bt=0;
                p[i].tat=x;
                p[i].wt=p[i].tat-p[i].tbt;
                y++;
                if(y==n)
                {
                    break;
                }
            
            }
        }
        if(i==n-1)
        {
            i=0;
        }
        else{
            i=i+1;
        }
    }
    printf("\nPROCESS ID\tBURST TME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].tbt,p[i].wt,p[i].tat);
    }
    return 0;
}