#include <stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Stores allocated block for each process

    for (int i = 0; i < n; i++)
        allocation[i] = -1; // Initially, no process is allocated

    // Worst Fit allocation logic
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j; // Find the largest available block
                }
            }
        }

        // If a worst fit block is found, allocate it
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
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

    // Perform Worst Fit Allocation
    printf("\nWorst Fit Allocation:\n");
    worstFit(blockSize, m, processSize, n);

    return 0;
}
