#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char name[100];
	char phone[20];
	struct Node* next;
}Node;

Node* addContact(Node* head, const char* name, const char* phone) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	strcpy(newNode->phone, phone);
	newNode->next = head;
	printf("����ó : %s[%s] �߰�\n", name, phone);
	return newNode;
}

void searchContact(Node* head, const char* name) {
	Node* current = head;
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			printf("�˻� ��� : %s�� ��ȭ��ȣ - %s", current->name, current->phone);
			return;
		}
		current = current->next;
	}
	printf("%s �̸��� ����ó�� �����ϴ�.\n", name);
}

Node* deleteContact(Node* head, const char* name) {
	Node* current = head;
	Node* prev = NULL;

	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			if (prev == NULL) {
				head = current->next;
			}
			else {
				prev->next = current->next;
			}
			printf("���� �Ϸ� : %s�� ��ȭ��ȣ - %s\n", current->name, current->phone);
			free(current);
			return head;
		}
		prev = current;
		current = current->next;
	}
	printf("%s �̸��� ����ó�� �����ϴ�.\n", name);
}

void displayContacts(Node* head) {
	if (head == NULL) {
		printf("��ȭ��ȣ�ΰ� ��� �ֽ��ϴ�.\n");
		return;
	}
	printf("���� ��ȭ��ȣ��-----\n");
	Node* current = head;
	while (current != NULL) {
		printf("%s�� ��ȭ��ȣ - %s\n", current->name, current->phone);
		current = current->next;
	}
}

void freeList(Node* head) {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	printf("��� �޸� ����\n");
}

int main() {
	Node* head = NULL;
	int choice;
	char name[20];
	char phone[20];

	while (1) {
		printf("��ȭ��ȣ�� ����\n");
		printf("1. ����ó �߰�\n");
		printf("2. ����ó �˻�\n");
		printf("3. ����ó ����\n");
		printf("4. ����ó ����\n");
		printf("5. ����\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("�̸� : ");
			scanf("%s", name);
			printf("��ȭ��ȣ : ");
			scanf("%s", phone);
			head = addContact(head, name, phone);
			break;
		case 2:
			printf("�̸� : ");
			scanf("%s", name);
			searchContact(head, name);
			break;
		case 3:
			printf("�̸� : ");
			scanf("%s", name);
			head = deleteContact(head, name);
			break;
		case 4:
			displayContacts(head);
			break;
		case 5:
			freeList(head);
			return 0;
		default:
			printf("�߸��� �� �Է�. �ٽ� �Է��ϼ���.\n");
			break;
		}
	}
}