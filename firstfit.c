#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int firstfit(int blocksize[],int m,int processsize[],int n)
{
    int allocation[n];
    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(blocksize[j]>=processsize[i])
                {
                    allocation[i]=j;
                    blocksize[j]-=processsize[i];
                    break;
                }
            }
        }
        printf("\nProcess No.\tProcess Size\tBlock No.\n");
        for(int i=0;i<n;i++)
        {
            if(allocation[i]!=-1)
            {
            printf("%d\t\t%d\t\t%d\n",i+1,processsize[i],allocation[i]+1);
            }
            else
            {
            printf("%d\t\t%d\t\tNot Allocated\n",i+1,processsize[i]);
            }
        }
        return 0;
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
    firstfit(blocksize,m,processsize,n);
    return 0;

}