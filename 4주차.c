#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5


void inputstock(int *stock);
void sellProducts(int *stock, int *sell);
void showStatus(int* stock, int* sell,char *name);
void productName(char* name);
void clearBuffer();

int main() {
	int stock[NUM] = { 0 };
	int sell[NUM] = { 0 };
	char name[NUM][100];

	int n;

	printf("[���θ� ���� ���α׷�]\n");
	while (1) {
		printf("���ϴ� �޴��� �����ϼ���.(1.�԰�,2.�Ǹ�,3.��ǰ��Ȳ,4.��ǰ�� �Է�, 5.����) : ");
		scanf("%d", &n);

		switch (n) {
		case 1:
			inputstock(stock);
			break;
		case 2:
			sellProducts(stock, sell);
			break;
		case 3:
			showStatus(stock, sell,name);
			break;
		case 4:
			productName(name);
			break;
		case 5:
			printf("���α׷��� �����մϴ�.");
			exit(0);
		default:
			printf("�߸��� �Է��Դϴ�.\n");
			clearBuffer();
			continue;
		}
	}
	return 0;
}

void clearBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void inputstock(int *stock) {
	int option, id, amount;

	printf("�԰�����Է� : ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է� 2�� ���� : ");
	scanf("%d", &option);

	if (option == 1) {
		for (int i = 0; i < NUM; i++) {
			if (scanf("%d", &amount) != 1 || amount < 0) {
				printf("�߸��� �Է��Դϴ�.\n");
				clearBuffer();
				return;
			}
			*(stock + i) += amount;
		}
	}
	else if (option == 2) {
		printf("��ǰ ID : ");
		scanf("%d", &id);
		if (id < 1 || id > NUM) {
			printf("�߸��� ID�Դϴ�.\n");
			clearBuffer();
			return;
		}
		else {
			printf("�԰���� : ");
			scanf("%d", &amount);
			if (amount < 0) {
				printf("�߸��� �Է��Դϴ�.\n");
				clearBuffer();
				return;
			}
			*(stock + id - 1) += amount;
		}
	}
	else {
		printf("�߸��� �Է��Դϴ�.\n");
		clearBuffer();
		return;
	}
}

void sellProducts(int *stock, int *sell) {
	int option, id, amount;

	printf("�Ǹż��� �Է� : ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է� 2�� ���� : ");
	scanf("%d", &option);

	if (option == 1) {
		for (int i = 0; i < NUM; i++) {
			if (scanf("%d", &amount) != 1 || amount < 0) {
				printf("�߸��� �Է��Դϴ�.\n");
				clearBuffer();
				return;
			}
			if (amount <= *(stock + i)) {
				*(stock + i) -= amount;
				*(sell + i) += amount;
			}
			else {
				printf("��ǰ %d�� ��� �����մϴ�. (���� ��� : %d)\n", i + 1, *(stock + i));
			}
		}
	}
	else if (option == 2) {
		printf("��ǰ ID : ");
		scanf("%d", &id);
		if (id < 1 || id > NUM) {
			printf("�߸��� ID�Դϴ�.\n");
			clearBuffer();
			return;
		}
		else {
			printf("�Ǹż��� : ");
			scanf("%d", &amount);
			if (amount < 0) {
				printf("�߸��� �Է��Դϴ�.\n");
				clearBuffer();
				return;
			}
			if (amount <= *(stock + id - 1)) {
				*(stock + id - 1) -= amount;
				*(sell + id - 1) += amount;
			}
			else {
				printf("��ǰ %d�� ��� �����մϴ�. (���� ��� : %d)\n", id, *(stock + id - 1));
			}
		}
	}
	else {
		printf("�߸��� �Է��Դϴ�.\n");
		clearBuffer();
		return;
	}
}

void showStatus(int *stock, int *sell, char* name) {
	int totalSell = 0;
	int maxSell = *sell, minSell = *sell;
	int maxID = 1, minID = 1;

	for (int i = 0; i < NUM; i++) {
		totalSell += *(sell + i);
		if (*(sell + i) > maxSell) {
			maxSell = *(sell + i);
			maxID = i + 1;
		}
		if (*(sell + i) < minSell) {
			minSell = *(sell + i);
			minID = i + 1;
		}
	}
	int totalStock = 0;
	for (int i = 0; i < NUM; i++) {
		totalStock += *(stock + i);
	}

	float sellRate = (float)totalSell / (totalSell + totalStock) * 100;

	printf("\[��ǰ ��Ȳ]\n");
	printf("��� ���� : ");
	for (int i = 0; i < NUM; i++) {
		printf("%d ", *(stock + i));
	}
	printf("\n�� �Ǹŷ� : %d (�Ǹ��� %.2f%%)\n", totalSell, sellRate);
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ�� : %s , �Ǹŷ� %d\n", maxID, name + ((maxID - 1) * 100), maxSell);
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ�� : %s , �Ǹŷ� %d\n", minID, name + ((minID - 1) * 100), minSell);

	for (int i = 0; i < NUM; i++) {
		if (*(stock + i) <= 2) {
			printf("��ǰ ID %d : ��ǰ�� : %s ������(%d)\n", i + 1, name + (i * 100), *(stock + i));
		}
	}
}

void productName(char *name) {

	for (int i = 0; i < NUM; i++) {
		printf("ID %d ��ǰ�� : ", i + 1);
		scanf("%s", name+(i*100));
	}
	return;
}