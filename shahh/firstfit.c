#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Stores allocated block for each process

    for (int i = 0; i < n; i++)
        allocation[i] = -1; // Initially, no process is allocated

    // First Fit allocation logic
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) { 
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    // Display allocation
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
    }
}

int main() {
    int m, n;

    // User input for blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter sizes of memory blocks: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    // User input for processes
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter sizes of processes: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    // Perform First Fit Allocation
    printf("\nFirst Fit Allocation:\n");
    firstFit(blockSize, m, processSize, n);

    return 0;
}
