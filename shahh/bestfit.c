#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Stores allocated block for each process

    for (int i = 0; i < n; i++)
        allocation[i] = -1; // Initially, no process is allocated

    // Best Fit allocation logic
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j; // Find the smallest sufficient block
                }
            }
        }

        // If a best fit block is found, allocate it
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
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

    // Perform Best Fit Allocation
    printf("\nBest Fit Allocation:\n");
    bestFit(blockSize, m, processSize, n);

    return 0;
}
