#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, total_movement = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n];

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSequence of head movements:\n");
    for (i = 0; i < n; i++) {
        printf("Head moves from %d to %d\n", head, request[i]);
        total_movement += abs(request[i] - head);
        head = request[i];
    }

    printf("\nTotal head movement = %d cylinders\n", total_movement);

    return 0;
}
