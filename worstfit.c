#include <stdio.h>
void worstfit(int blocksize[],int m,int processsize[],int n)
{
    int allocation[n];
    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        int worstidx=-1;
        for(int j=0;j<m;j++)
        {
            if(blocksize[j]>=processsize[i])
            {
                if(worstidx==-1||blocksize[j]>blocksize[worstidx])
                {
                    worstidx=j;
                }
            }
        }
        if(worstidx!=-1)
        {
            allocation[i]=worstidx;
            blocksize[worstidx]-=processsize[i];
        }
    }
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(int i=0;i<n;i++)
    {
        if(allocation[i]!=-1)
        {
            printf("%d\t\t%d\t\t%d\n",i+1,processsize[i],allocation[i]+1);
        }
        else
        {
            printf("%d\t\t%d\t\tNOT ALLOCATED\n",i+1,processsize[i]);
        }
    }
}
int main()
{
    int m,n,i;

    printf("Enter the number of blocks");
    scanf("%d",&m);
    int blocksize[m];
    for(i=0;i<m;i++)
    {
        printf("Enter the size of each block");
        scanf("%d",&blocksize[i]);
    }
    printf("Enter the number of process");
    scanf("%d",&n);
    int processsize[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the size of each process");
        scanf("%d",&processsize[i]);
    }
    worstfit(blocksize,m,processsize,n);
    return 0;

}