#include <stdio.h>
#include <stdlib.h>

// Structure for Priority Queue
struct Node {
    int data;
    int priority;
};

// Circular Queue Implementation
#define MAX_SIZE 5
int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

// Priority Queue Implementation
#define MAX_PRIORITY_QUEUE_SIZE 5
struct Node priorityQueue[MAX_PRIORITY_QUEUE_SIZE];
int priorityRear = -1;

// Function prototypes
void displayCircularQueue();
void displayPriorityQueue();
void enqueueCircular(int data);
void dequeueCircular();
void enqueuePriority(int data, int priority);
void dequeuePriority();

int main() {
    int choice;
    int data, priority;

    do {
        printf("\nMain Menu\n");
        printf("1. Circular Queue\n");
        printf("2. Priority Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("\nCircular Queue Menu\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to enqueue: ");
                            scanf("%d", &data);
                            enqueueCircular(data);
                            break;
                        case 2:
                            dequeueCircular();
                            break;
                        case 3:
                            displayCircularQueue();
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice! Please enter again.\n");
                    }
                } while (choice != 4);
                break;

            case 2:
                do {
                    printf("\nPriority Queue Menu\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to enqueue: ");
                            scanf("%d", &data);
                            printf("Enter priority: ");
                            scanf("%d", &priority);
                            enqueuePriority(data, priority);
                            break;
                        case 2:
                            dequeuePriority();
                            break;
                        case 3:
                            displayPriorityQueue();
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice! Please enter again.\n");
                    }
                } while (choice != 4);
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Circular Queue functions
void enqueueCircular(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Circular Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        circularQueue[rear] = data;
        printf("Enqueued %d\n", data);
    }
}

void dequeueCircular() {
    if (front == -1) {
        printf("Circular Queue is empty. Cannot dequeue.\n");
    } else {
        printf("Dequeued %d\n", circularQueue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void displayCircularQueue() {
    if (front == -1) {
        printf("Circular Queue is empty.\n");
    } else {
        printf("Circular Queue: ");
        int i = front;
        do {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

// Priority Queue functions
void enqueuePriority(int data, int priority) {
    if (priorityRear == MAX_PRIORITY_QUEUE_SIZE - 1) {
        printf("Priority Queue is full. Cannot enqueue.\n");
    } else {
        int i;
        for (i = priorityRear; i >= 0 && priority > priorityQueue[i].priority; i--) {
            priorityQueue[i + 1] = priorityQueue[i];
        }
        priorityQueue[i + 1].data = data;
        priorityQueue[i + 1].priority = priority;
        priorityRear++;
        printf("Enqueued %d with priority %d\n", data, priority);
    }
}


void dequeuePriority() {
    if (priorityRear == -1) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
    } else {
        int maxPriorityIndex = 0;
        for (int i = 1; i <= priorityRear; i++) {
            if (priorityQueue[i].priority > priorityQueue[maxPriorityIndex].priority) {
                maxPriorityIndex = i;
            }
        }
        printf("Dequeued %d with priority %d\n", priorityQueue[maxPriorityIndex].data, priorityQueue[maxPriorityIndex].priority);
        for (int i = maxPriorityIndex; i < priorityRear; i++) {
            priorityQueue[i] = priorityQueue[i + 1];
        }
        priorityRear--;
    }
}

void displayPriorityQueue() {
    if (priorityRear == -1) {
        printf("Priority Queue is empty.\n");
    } else {
        printf("Priority Queue: ");
        for (int i = 0; i <= priorityRear; i++) {
            //printf("(%d, %d) ", priorityQueue[i].data, priorityQueue[i].priority);
            printf("%d  ", priorityQueue[i].data);
        }
        printf("\n");
        printf("Priorities    : ");
        for (int i = 0; i <= priorityRear; i++) {
            //printf("(%d, %d) ", priorityQueue[i].data, priorityQueue[i].priority);
            printf("%d  ", priorityQueue[i].priority);
        }
        printf("\n");
    }
}
