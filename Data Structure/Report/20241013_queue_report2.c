#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10  // �ִ� �۾� ��⿭ ũ��

// ������ �۾� ����ü
typedef struct {
    char documentName[50];  // ���� �̸�
    int numPages;  // ���� ������ ��
} PrintJob;

typedef struct {
    PrintJob queue[SIZE];  // �۾� ��⿭ �迭
    int front;  // ù ��° �۾� �ε���
    int rear;   // ������ �۾� �ε���
} PrintQueue;

// �ʱ�ȭ �Լ�
void initQueue(PrintQueue* q) {
    q->front = 0;
    q->rear = 0;
}

// ť�� ��� �ִ��� Ȯ��
bool isEmpty(PrintQueue* q) {
    return q->front == q->rear;
}

// ť�� ���� á���� Ȯ��
bool isFull(PrintQueue* q) {
    return (q->rear + 1) % SIZE == q->front;
}

// �۾� �߰� �Լ�
bool enqueue(PrintQueue* q, char* documentName, int numPages) {
    if (numPages > 50) {
        printf("������ ���� 50���� �ʰ���. �۾��� �߰��� �� ����.\n");
        return false;
    }
    if (isFull(q)) {
        printf("��⿭�� ���� á���ϴ�. �۾��� �߰��� �� �����ϴ�.\n");
        return false;
    }
    strcpy(q->queue[q->rear].documentName, documentName);
    q->queue[q->rear].numPages = numPages;
    q->rear = (q->rear + 1) % SIZE;
    printf("�۾� '%s' (%d ������)�� ��⿭�� �߰��Ǿ����ϴ�.\n", documentName, numPages);
    return true;
}

// �۾� ���� �Լ�
PrintJob dequeue(PrintQueue* q) {
    if (isEmpty(q)) {
        printf("��⿭�� ��� �ֽ��ϴ�. �۾��� �����ϴ�.\n");
        PrintJob emptyJob = { "", 0 };
        return emptyJob;
    }
    PrintJob job = q->queue[q->front];
    q->front = (q->front + 1) % SIZE;
    return job;
}

// ��⿭ ���� ��� �Լ�
void printQueue(PrintQueue* q) {
    if (isEmpty(q)) {
        printf("��⿭�� ��� �ֽ��ϴ�.\n");
        return;
    }
    printf("���� ��� ���� �۾�:\n");
    int i = q->front;
    while (i != q->rear) {
        printf("- %s (%d ������)\n", q->queue[i].documentName, q->queue[i].numPages);
        i = (i + 1) % SIZE;
    }
}

void clearQueue(PrintQueue* q) {
    initQueue(q);
    printf("��⿭�� �ʱ�ȭ �Ǿ����ϴ�.\n");
}

bool cancelJob(PrintQueue* q, char* documentName) {
    if (isEmpty(q)) {
        printf("��⿭�� ��� �ֽ��ϴ�.");
        return;
    }
    int found = -1;
    for (int i = q->front; i != q->rear; i = (i + 1) % SIZE) {
        if (strcmp(q->queue[i].documentName, documentName) == 0) {
            found = i;
            break;
        }
    }
    if (found = -1) {
        printf("�ش� ���� ����.\n");
        return false;
    }
    for (int i = found; i != q->rear; i = (i + 1) % SIZE){
        q->queue[i] = q->queue[(i + 1) % SIZE];
    }
    q->rear = (q->rear - 1 + SIZE) % SIZE;
    printf("���� \'%s\'�� ��ҵǾ����ϴ�.\n", documentName);
    return true;
}

int main() {
    PrintQueue q;
    initQueue(&q);

    int choice;
    char documentName[50];
    int numPages;

    while (true) {
        printf("\n1. �۾� �߰�\n2. �۾� ó��\n3. ��⿭ ���\n4. �۾����\n5. ��⿭ �ʱ�ȭ\n6.����\n����:");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("���� �̸�: ");
            scanf("%s", documentName);
            printf("������ ��: ");
            scanf("%d", &numPages);
            enqueue(&q, documentName, numPages);
            break;
        case 2:
            PrintJob job = dequeue(&q);
            if (strlen(job.documentName) > 0) {
                printf("�۾� '%s' (%d ������)�� ó�� ���Դϴ�...\n", job.documentName, job.numPages);
            }
            break;
        case 3:
            printQueue(&q);
            break;
        case 4:
            printf("����� ���� �̸� : ");
            scanf("%s", documentName);
            cancelJob(&q, documentName);
            return 0;
        case 5:
            clearQueue(&q);
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���.\n");
            break;
        }
    }
}