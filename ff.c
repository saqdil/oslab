#include<stdio.h>
#include<string.h>

void firstFit(int blockSize[], int m, int processSize[], int n){
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0;i<n; i++){
        for(int j = 0; j<m; j++){
            if(blockSize[j] >= processSize[i]){
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\n Process No. \t Process Size \t Block No. \n");
    for(int i = 0; i<n; i++){
        printf("%d \t \t %d \t t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1); 
        else
            printf("Not Allocated");
        printf("\n");
    }
    printf("\n Free Blocks: \n");
    for(int i = 0; i <m ; i++){
        printf("Block %d -> %d\n", i+1,blockSize[i]);
    }
}

int main() {
    int m, n;

    // Input number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];

    // Input sizes of memory blocks
    printf("Enter the sizes of memory blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];

    // Input sizes of processes
    printf("Enter the sizes of processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    // Perform First Fit Allocation
    firstFit(blockSize, m, processSize, n);

    return 0;
}