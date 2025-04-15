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
        printf("ť�� ���� á���ϴ�.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;  
}

int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("ť�� ��� �ֽ��ϴ�.\n");
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
        printf("�޴��� �����Ͻÿ� (1. ����, 2. ����, 3. ť ������ ���, 4. ����) : ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            printf("������ ť�� �Է��Ͻÿ� : \n");
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