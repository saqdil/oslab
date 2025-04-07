#include <stdio.h>

struct Block {
    int size;
    int next;  // Index of the next block, -1 means end
};

void firstFit(struct Block blocks[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < m && blocks[j].next != -2) {  // -2 marks an invalid/unused block
            if (blocks[j].size >= processSize[i]) {
                allocation[i]=j;
                blocks[j].size-=processSize[i];
                break;
            }
            j = blocks[j].next == -1 ? m : blocks[j].next;
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%s%d\n", i + 1, processSize[i], 
               allocation[i] != -1 ? "" : "Not Allocated\n", 
               allocation[i] != -1 ? allocation[i] + 1 : 0);
}

int main() {
    int m, n;
    struct Block blocks[10];
    int processSize[10];

    printf("Enter number of blocks: ");
    scanf("%d", &m);
    printf("Enter size of blocks: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blocks[i].size);
        blocks[i].next = (i == m - 1) ? -1 : i + 1;  // Link to next index
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter size of processes: ");
    for (int i = 0; i < n; i++) scanf("%d", &processSize[i]);

    firstFit(blocks, m, processSize, n);
    return 0;
}