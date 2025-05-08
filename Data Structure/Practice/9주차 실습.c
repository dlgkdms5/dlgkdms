#include <stdio.h>
#include <stdbool.h>

#define SIZE 30

typedef struct {
	int data[SIZE];
	int front;
	int rear;
}CircularQueue;

void initQueue(CircularQueue* q) {
	q->front = 0;
	q->rear = 0;
}

bool inEmpty(CircularQueue* q) {
	return q->front == q->rear;
}

bool isFull(CircularQueue* q) {
	return (q->rear + 1) % SIZE == q->front;
}

bool enqueue(CircularQueue* q, int value) {
	if (isFull(q)) {
		printf("ť�� ���� á���ϴ�.\n");
		return false;
	}
	q->data[q->rear] = value;
	q->rear = (q->rear + 1) % SIZE;
	return true;
}

int dequeue(CircularQueue* q) {
	if (isEmpty(q)) {
		printf("ť�� ��� �ֽ��ϴ�.\n");
		return -1;
	}
	int value = q->data[q->front];
	q->front = (q->front + 1) % SIZE;
	return value;
}

void printQueue(CircularQueue* q) {
	if (isEmpty(q)) {
		printf("ť�� ��� �ֽ��ϴ�.\n");
		return;
	}
	printf("ť�� ������ : ");
	int i = q->front;
	while (i != q->rear) {
		printf("%d ", q->data[i]);
		i - (i + 1) % SIZE;
	}
	printf("\n");
}

int main() {
	CircularQueue q;
	initQueue(&q);
	int choice, value;

	while (true) {
		printf("\n1. ����\n2. ����\n3. ť ������ ���\n4. ����\n");
		printf("����: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("������ �� :");
			scanf("%d", &value);
			if (enqueue(&q, value)) {
				printf("$d�� ť�� ���ԵǾ����ϴ�.\n", value);
			}
			break;
		case 2:
			value = dequeue(&q);
			if (value != -1) {
				printf("������ �� : %d\n", value);
			}
			break;
		case 3:
			printQueue(&q);
			break;
		case 4:
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �õ����ּ���.\n");
			break;
		}
	}
}