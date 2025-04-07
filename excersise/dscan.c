#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, head, size, direction;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int request[n], temp;
    printf("Enter the request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size (e.g., 200): ");
    scanf("%d", &size);

    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    // Sort the requests
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (request[i] > request[j]) {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    int total_movement = 0;
    printf("\nSequence of head movements:\n");

    // Find where head fits in sorted array
    int index;
    for (i = 0; i < n; i++) {
        if (request[i] > head) {
            index = i;
            break;
        }
    }

    if (direction == 1) { // Moving right
        for (i = index; i < n; i++) {
            printf("Head moves from %d to %d\n", head, request[i]);
            total_movement += abs(request[i] - head);
            head = request[i];
        }
        // Go to end
        total_movement += abs((size - 1) - head);
        head = size - 1;
        // Reverse
        for (i = index - 1; i >= 0; i--) {
            printf("Head moves from %d to %d\n", head, request[i]);
            total_movement += abs(request[i] - head);
            head = request[i];
        }
    } else { // Moving left
        int index=n;
        for (i = index - 1; i >= 0; i--) {
            printf("Head moves from %d to %d\n", head, request[i]);
            total_movement += abs(request[i] - head);
            head = request[i];
        }
        // Go to start
        total_movement += abs(head - 0);
        head = 0;
        // Reverse
        for (i = index; i < n; i++) {
            printf("Head moves from %d to %d\n", head, request[i]);
            total_movement += abs(request[i] - head);
            head = request[i];
        }
    }

    printf("\nTotal head movement = %d cylinders\n", total_movement);
    return 0;
}
