#include<stdio.h>
int main(){
    int n,arrival[10],burst[10],waiting[10],tat[10];
    printf("enter the number od process");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("arrivaltime,burst time of process %d\t\n",i+1);
        scanf("%d\t %d",&arrival[i],&burst[i]);
    }
        waiting[0]=0;
        tat[0]=burst[0];
    
    for(int i=1;i<n;i++){
        waiting[i]=waiting[i-1]+burst[i-1];
        tat[i]=waiting[i]+burst[i];
    }
    printf("\npid\tarrival\tburst\twaiting\ttat\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t%d\t%d\t%d\n",i+1,arrival[i],burst[i],waiting[i],tat[i]);
    }

}