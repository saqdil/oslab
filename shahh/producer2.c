#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3;  // Buffer size is 3

// User-defined wait (P) function
int wait(int s) {
    return s - 1;
}

// User-defined signal (V) function
int signal(int s) {
    return s + 1;
}

// Producer function
void producer() {
    if (mutex == 1 && empty > 0) {
        mutex = wait(mutex);
        full = signal(full);
        empty = wait(empty);

        printf("Producer produced an item.\n");

        mutex = signal(mutex);
    } else {
        printf("Buffer is full! Producer waiting...\n");
    }
}

// Consumer function
void consumer() {
    if (mutex == 1 && full > 0) {
        mutex = wait(mutex);
        full = wait(full);
        empty = signal(empty);

        printf("Consumer consumed an item.\n");

        mutex = signal(mutex);
    } else {
        printf("Buffer is empty! Consumer waiting...\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
