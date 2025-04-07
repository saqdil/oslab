#include<stdio.h>
#include<stdlib.h>

typedef struct Block{
    int size;
    int allocated;
    int process_id;
    struct Block* next;
}Block;

Block* head = NULL;

void create_memory(int sizes[], int n){
    for(int i = 0; i < n; i++){
        Block* new_block = (Block*)malloc(sizeof(Block));
        new_block-> size = sizes[i];
        new_block-> allocated = 0;
        new_block->process_id = -1;
        new_block->next = NULL;

        if(head == NULL) head = new_block;
        else{
            Block* temp = head;
            while (temp->next) temp = temp->next;
            temp -> next = new_block;
        }
    }
}

void allocate_first_fit(int pid, int size){
    Block* temp = head;
    while(temp){
        if(!temp->allocated && temp->size >= size){
            temp->allocated = 1;
            temp->process_id = pid;
            printf("process %d allocated in block of size %d (first fit)\n", pid , temp->size);
            return;
        }
        temp = temp-> next;
    }
    printf("Process %d couldn't be allocatetd\n", pid);
}

void display_memory(){
    Block* temp = head;

    printf("\n Memory Blocks: \n");
    int i = 1;
    while(temp){
        printf("Block %d: Size = %d | ", i++, temp->size);
        if(temp->allocated)
            printf("Allocated to Process %d\n", temp->process_id);
        else{
            printf("Free \n");
        } 
        temp = temp->next;   
        
    }
}

int main() {
    int n, m;
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    int sizes[n];
    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < n; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &sizes[i]);
    }
    create_memory(sizes, n);

    printf("Enter number of processes: ");
    scanf("%d", &m);

    for (int i = 1; i <= m; i++) {
        int size;
        printf("Enter memory needed for Process %d: ", i);
        scanf("%d", &size);
        allocate_first_fit(i, size);
    }

    display_memory();
    return 0;
}