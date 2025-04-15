#include <stdio.h>
#include <stdbool.h>

#define SIZE 30

typedef struct {
    int data[SIZE];  
    int front;  
    int rear;  
} LinearQueue;

void initQueue(LinearQueue* q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(LinearQueue* q) {
    return q->rear < q->front;  
}

bool isFull(LinearQueue* q) {
    return q->rear == SIZE - 1;  
}

bool enqueue(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;  
}

int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        initQueue(&q);
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

int main() {
    LinearQueue q;
    initQueue(&q);
    int menu;
    int value;

    while (true) {
        printf("메뉴를 선택하시오 (1. 삽입, 2. 삭제, 3. 큐 데이터 출력, 4. 종료) : ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            printf("삽입할 큐를 입력하시오 : \n");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            printf("Dequeue: %d\n", dequeue(&q));
            break;
        case 3:
            while (!isEmpty(&q)) {
                printf("%d\n", dequeue(&q));
            }
            break;
        case 4:
            return 0;
        }
    }
}
