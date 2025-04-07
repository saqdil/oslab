#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, head, size;
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

    // Find index where current head is less than request
    int index;
    for (i = 0; i < n; i++) {
        if (request[i] > head) {
            index = i;
            break;
        }
    }

    // Move right
    for (i = index; i < n; i++) {
        printf("Head moves from %d to %d\n", head, request[i]);
        total_movement += abs(request[i] - head);
        head = request[i];
    }

    // Go to end and jump to start
    if (index != 0) {
        total_movement += abs((size - 1) - head); // Go to end
        total_movement += (size - 1);             // Jump from end to 0
        head = 0;

        for (i = 0; i < index; i++) {
            printf("Head moves from %d to %d\n", head, request[i]);
            total_movement += abs(request[i] - head);
            head = request[i];
        }
    }

    printf("\nTotal head movement = %d cylinders\n", total_movement);
    return 0;
}
