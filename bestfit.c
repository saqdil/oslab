#include <stdio.h>
void bestfit(int blocksize[],int m,int processsize[],int n)
{
    int i;
    int allocation[n];
    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        int bestidx=-1;
        for(int j=0;j<m;j++)
        {
            if(blocksize[j]>=processsize[i])
            {
                if(bestidx==-1||blocksize[j]<blocksize[bestidx])
                {
                    bestidx=j;
                }
            }
        }
        if (bestidx!=-1)
        {
            allocation[i]=bestidx;
            blocksize[bestidx]-=processsize[i];
        }
    }
        printf("\nProcess No.\tProcess Size\tBlock No.\n");
        for(i=0;i<n;i++)
        {
            if(allocation[i]!=-1)
            {
                printf("%d\t\t%d\t\t%d\n",i+1,processsize[i],allocation[i]+1);
            }
            else
            {
                printf("%d\t\t%d\t\tNot allocated\n",i+1,processsize[i]);
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
    bestfit(blocksize,m,processsize,n);
    return 0;

}