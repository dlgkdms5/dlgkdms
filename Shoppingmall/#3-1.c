#include <stdio.h>
#include <stdlib.h>
#define NUM 5

int stock[NUM] = { 0 };
int sell[NUM] = { 0 };

void inputstock();
void sellProducts();
void showStatus();
void clearBuffer();

int main() {

	int n;

	printf("[���θ� ���� ���α׷�]\n");
	while (1) {
		printf("���ϴ� �޴��� �����ϼ���.(1.�԰�,2.�Ǹ�,3.��ǰ��Ȳ,4.����) : ");
		scanf("%d", &n);

		switch (n) {
		case 1:
			inputstock();
			break;
		case 2:
			sellProducts();
			break;
		case 3:
			showStatus();
			break;
		case 4:
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

void inputstock() {
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
			stock[i] += amount;
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
			stock[id - 1] += amount;
		}
	}
	else {
		printf("�߸��� �Է��Դϴ�.\n");
		clearBuffer();
		return;
	}
}

void sellProducts() {
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
			if (amount <= stock[i]) {
				stock[i] -= amount;
				sell[i] += amount;
			}
			else {
				printf("��ǰ %d�� ��� �����մϴ�. (���� ��� : %d)\n", i + 1, stock[i]);
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
			if (amount <= stock[id - 1]) {
				stock[id - 1] -= amount;
				sell[id - 1] += amount;
			}
			else {
				printf("��ǰ %d�� ��� �����մϴ�. (���� ��� : %d)\n", id, stock[id - 1]);
			}
		}
	}
	else {
		printf("�߸��� �Է��Դϴ�.\n");
		clearBuffer();
		return;
	}
}

void showStatus() {
	int totalSell = 0;
	int maxSell = sell[0], minSell = sell[0];
	int maxID = 1, minID = 1;

	for (int i = 0; i < NUM; i++) {
		totalSell += sell[i];
		if (sell[i] > maxSell) {
			maxSell = sell[i];
			maxID = i + 1;
		}
		if (sell[i] < minSell) {
			minSell = sell[i];
			minID = i + 1;
		}
	}

	float sellRate = (float)totalSell / (totalSell + stock[0] + stock[1] + stock[2] + stock[3] + stock[4]) * 100;

	printf("\[��ǰ ��Ȳ]\n");
	printf("��� ���� : ");
	for (int i = 0; i < NUM; i++) {
		printf("%d ", stock[i]);
	}
	printf("\n�� �Ǹŷ� : %d (�Ǹ��� %.2f%%)\n", totalSell, sellRate);
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", maxID, maxSell);
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", minID, minSell);

	for (int i = 0; i < NUM; i++) {
		if (stock[i] <= 2) {
			printf("��ǰ ID %d : ������(%d)\n", i + 1, stock[i]);
		}
	}
}