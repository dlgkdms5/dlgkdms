#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct {
	char documentName[50];
	int numPages;
} PrintJob;

typedef struct {
	PrintJob queue[SIZE];
	int front;
	int rear;
}PrintQueue;

void initQueue(PrintQueue* q) {
	q->front = 0;
	q->rear = 0;
}

bool isEmpty(PrintQueue* q) {
	return q->front == q->rear;
}

bool isFull(PrintQueue* q) {
	return (q->rear + 1) % SIZE == q->front;
}

bool enqueue(PrintQueue* q, char* documentName, int numPages) {
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

void printQueue(PrintQueue* q) {
	if (isEmpty(q)) {
		printf("��⿭�� ��� �ֽ��ϴ�.\n");
		return;
	}
	printf("���� ��� ���� �۾� : \n");
	int i = q->front;
	while (i != q->rear) {
		printf("- %s (%d ������)\n", q->queue[i].documentName, q->queue[i].numPages);
		i = (i + 1) % SIZE;
	}
}

int main() {
	PrintQueue q;
	initQueue(&q);

	int choice;
	char documentName[50];
	int numPages;

	while (true) {
		printf("\n1. �۾� �߰�\n2. �۾� ó��\n3. ��⿭ ���\n4. ����\n����: ");
		scanf("%d", % choice);

		switch (choice) {
		case 1:
			printf("���� �̸� : ");
			scanf("%s", documentName);
			printf("������ �� : ");
			scanf("%d", &numPages);
			enqueue(&q, documentName, numPages);
			break;
		case 3:
			printQueue(&q);
			break;
		case 4:
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���.\n");
			break;
		}
	}
}