#include <stdio.h>
#include <unistd.h>

int buffer[100];  // Large enough buffer for user-defined size
int count = 0;     // Keeps track of the number of items in the buffer
int BUFFER_SIZE;   // User-defined buffer size

void producer(int totalItems, int delay) {
    for (int i = 1; i <= totalItems; i++) {
        if (count < BUFFER_SIZE) { 
            buffer[count] = i; 
            printf("Produced: %d\n", i);
            count++;
        } else {
            printf("Buffer Full! Producer waiting...\n");
            i--;  // Retry the same item
        }
        sleep(delay);
    }
}

void consumer(int totalItems, int delay) {
    for (int i = 1; i <= totalItems; i++) {
        if (count > 0) { 
            printf("\tConsumed: %d\n", buffer[count - 1]);
            count--;
        } else {
            printf("\tBuffer Empty! Consumer waiting...\n");
            i--;  // Retry to consume
        }
        sleep(delay);
    }
}

int main() {
    int totalItems, producerDelay, consumerDelay;

    // User Input
    printf("Enter buffer size: ");
    scanf("%d", &BUFFER_SIZE);

    printf("Enter total items to produce: ");
    scanf("%d", &totalItems);

    printf("Enter producer delay (seconds): ");
    scanf("%d", &producerDelay);

    printf("Enter consumer delay (seconds): ");
    scanf("%d", &consumerDelay);

    // Run Producer and Consumer
    producer(totalItems, producerDelay);
    consumer(totalItems, consumerDelay);

    return 0;
}
