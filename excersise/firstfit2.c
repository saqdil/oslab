#include<stdio.h>
void firstfit(int blocksize[],int m,int processSize[],int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blocksize[j]>=processSize[i])
            {
                allocation[i]=j;
                blocksize[j]-=processSize[i];
                break;
                
            }
        }
    }
    printf("\nprocess no:\tprocess size\tblock no\n");
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            printf("%d\t\t%d\t\t%d\n",i+1,processSize[i],allocation[i]+1);
        }
        else{
            printf("%d\t\t%d\t\tnot allocated\n",i+1,processSize[i]);
        }
    }
}
int main(){
    int m,n;
    int processSize[10],blocksize[10];
    printf("enter the number of blocks:");
    scanf("%d",&m);
    printf("enter the size of blocks:");
    for(int i=0;i<m;i++){
        scanf("%d",&blocksize[i]);
    }
    printf("enter the number of processes:");
    scanf("%d",&n);
    printf("enter the size of processes:");
    for(int i=0;i<n;i++){
        scanf("%d",&processSize[i]);
    }
    firstfit(blocksize,m,processSize,n);

}