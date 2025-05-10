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

//삽입 테스트
int main() {
	Node* head = NULL;

	head = insertFirst(head, 30);
	head = insertFirst(head, 20);
	head = insertFirst(head, 10);
	head = insertLast(head, 70);
	head = insertLast(head, 80);
	head = insertLast(head, 90);
	insertAfterValue(head, 30, 40);
	insertAfterValue(head, 40, 50);
	insertAfterValue(head, 50, 60);

	Node* current = head;
	while (current != NULL) {
		printf("%d-> ", current->data);
		current = current->next;
	}
	printf("NULL\n");

	return 0;
}