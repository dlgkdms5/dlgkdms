#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

int main() {
	Node* head = NULL;

	if (head == NULL) {
		printf("����Ʈ�� �ʱ�ȭ�Ǿ����ϴ�. ���� ����Ʈ�� ��� �ֽ��ϴ�.");
	}

	return 0;
}