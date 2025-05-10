#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

int main() {
	Node* head = NULL;

	if (head == NULL) {
		printf("리스트가 초기화되었습니다. 현재 리스트는 비어 있습니다.");
	}

	return 0;
}
