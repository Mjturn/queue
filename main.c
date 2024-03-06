#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void enqueue(int** queue, int value, unsigned int* size, unsigned int* capacity) {
    if(*size >= *capacity) {
        *capacity += 10;
        *queue = realloc(*queue, *capacity * sizeof(int));

        if(*queue == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }
    
    (*queue)[*size] = value;
    (*size)++;
}

void dequeue(int** queue, unsigned int* size) {
    for(int i = 0; i < *size; i++) {
        (*queue)[i] = (*queue)[i + 1];
    }

    if(*size > 0) {
        (*size)--;
    } else {
        return;
    }
}

int peek(int* queue) {
    return queue[0];
}

bool is_empty(unsigned int size) {
    return size <= 0;
}

int main() {
    unsigned int size = 0;
    unsigned int capacity = 5;
    int* queue = (int*)malloc(capacity * sizeof(int));

    if(queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    enqueue(&queue, 1, &size, &capacity);
    enqueue(&queue, 2, &size, &capacity);
    enqueue(&queue, 3, &size, &capacity);
    enqueue(&queue, 4, &size, &capacity);
    enqueue(&queue, 5, &size, &capacity);
    int front = peek(queue);

    printf("Queue:\n");

    for(int i = 0; i < size; i++) {
        printf("%d ", queue[i]);
    }

    free(queue);
    printf("\n");
    printf("Front of Queue: %d\n", front);

    if(is_empty(size)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }
    
    printf("Size: %u\n", size);
    printf("Capacity: %u\n", capacity);
   
    return 0;
}
