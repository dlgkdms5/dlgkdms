#include <stdio.h>
#include <stdlib.h>

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

void insertAfterValue(Node* head, int targetValue, int newData) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == targetValue) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("�� %d�� ���� ��带 ã�� �� �����ϴ�. �������� �ʽ��ϴ�.\n", targetValue);
}

Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
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
    current->next = NULL;

    return head;
}

Node* deleteNode(Node* head, int targetValue) {
    if (head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
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
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("��� ��尡 ���ŵǾ����ϴ�.\n");
}

int searchValue1(Node* head, int val) {
    if (head == NULL) {
        printf("Head Node�� NULL �Դϴ�.\n");
        return -1;
    }
    Node* current = head;
    int pos = 0;
    while (current != NULL) {
        ++pos;
        if (current->data == val) return pos;
        else current = current->next;
    }
    printf("���� �����ϴ�.\n");
    return -1;
}
void searchValue2(Node* head, int val) {
    if (head == NULL) {
        printf("Head Node�� NULL �Դϴ�.\n");
        return;
    }
    if (head->data == val) {
        printf("%d�� ������ : ����\n", val);
        printf("%d�� ������ : %d\n", val, head->next->data);
        return;
    }
    Node* current = head;
    while (current->next != NULL && current->next->data != val) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("%d�� ã�� �� �����ϴ�.\n", val);
        return;
    }
    printf("%d�� ������ : ����\n", val, current->data);
    printf("%d�� ������ : %d\n", val, current->next->next->data);
}

int main() {
    Node* head = NULL;
    int value = 0;

    for (int i = 0; i < 10; i++) {
        head = insertLast(head, i);
    }
    
    printList(head);
    /*searchValue1
      value = searchValue(head, 10);
      printf("value = %d\n", value);
    */
    // searchValue2
    searchValue2(head, 5);
    freeList(head);
    return 0;
}