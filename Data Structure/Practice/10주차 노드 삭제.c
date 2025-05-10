#include <stdio.h>
#include <stdlib.h>


//1. 리스트의 맨 앞에 삽입
typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* insertFirst(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}

	newNode->next = head;
	return newNode;
}

int main() {
	Node* head = NULL;

	head = insertFirst(head, 10);
	head = insertFirst(head, 20);
	head = insertFirst(head, 30);

	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");

	return 0;
}

// 리스트의 맨 뒤에 삽입
Node* insertLast(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}

	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;

	return head;
}

//리스트의 특정 위치에 삽입
void insertAfterValue(Node* head, int targetValue, int newData) {
	Node* current = head;

	while (current != NULL) {
		if (current->data == targetValue) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = newData;
			newNode->next = current->next;
			newNode->next = newNode;
			return;
		}
		current = current->next;
	}

	printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}

//1. 리스트의 맨 앞 노드(헤드 노드) 삭제
Node* deleteHead(Node* head) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다. 삭제할 녿가 없습니다.\n");
		return NULL;
	}

	Node* temp = head;
	head = head->next;
	free(temp);

	return head;
}

//2. 리스트의 맨 뒤 노드 삭제
Node* deleteLast(Node* head) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}

	if (head->next == NULL) {
		free(head);
		return NULL;
	}

	Node* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	free(current->next);
	current = current->next;

	return head;
}

//3. 특정 위치의 노드 삭제
Node* deleteNode(Node* head, int targetValue) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}

	if (head->data == targetValue) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}

	Node* current = head;
	while (current->next != NULL && current->next->data != targetValue) {
		current = current->next;
	}

	if (current->next == NULL) {
		printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
		return head;
	}

	Node* temp = current->next;
	current->next = current->next->next;
	free(temp);

	return head;
}

//4. 삭제 테스트
int main() {
	Node* head = NULL;

	head = insertFirst(head, 30);
	head = insertFirst(head, 20);
	head = insertFirst(head, 10);
	head = insertLast(head, 70);
	head = insertLast(head, 80);
	head = insertLast(head, 90);
	insertAfter(head, 30, 40);
	insertAfter(head, 40, 50);
	insertAfter(head, 50, 60);

	head = deleteHead(head);
	head = deleteLast(head);
	head = deleteNode(head, 40);
	head = deleteNode(head, 70);
	head = deleteNode(head, 100);

	Node* current = head;
	while (current != NULL) {
		printf("%d-> ", current->data);
		current = current->next;
	}
	printf("NULL\n");

	return 0;
}