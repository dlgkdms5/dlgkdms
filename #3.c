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

	printf("[쇼핑몰 관리 프로그램]\n");
	while (1) {
		printf("원하는 메뉴를 선택하세요.(1.입고,2.판매,3.상품현황,4.종료) : ");
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
			printf("프로그램을 종료합니다.");
			exit(0);
		default:
			printf("잘못된 입력입니다.\n");
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

	printf("입고수량입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택 : ");
	scanf("%d", &option);

	if (option == 1) {
		for (int i = 0; i < NUM; i++) {
			if (scanf("%d", &amount) != 1 || amount < 0) {
				printf("잘못된 입력입니다.\n");
				clearBuffer();
				return;
			}
			stock[i] += amount;
		}
	}
	else if (option == 2) {
		printf("상품 ID : ");
		scanf("%d", &id);
		if (id < 1 || id > NUM) {
			printf("잘못된 ID입니다.\n");
			clearBuffer();
			return;
		}
		else {
			printf("입고수량 : ");
			scanf("%d", &amount);
			if (amount < 0) {
				printf("잘못된 입력입니다.\n");
				clearBuffer();
				return;
			}
			stock[id - 1] += amount;
		}
	}
	else {
		printf("잘못된 입력입니다.\n");
		clearBuffer();
		return;
	}
}

void sellProducts() {
	int option, id, amount;

	printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택 : ");
	scanf("%d", &option);

	if (option == 1) {
		for (int i = 0; i < NUM; i++) {
			if (scanf("%d", &amount) != 1 || amount < 0) {
				printf("잘못된 입력입니다.\n");
				clearBuffer();
				return;
			}
			if (amount <= stock[i]) {
				stock[i] -= amount;
				sell[i] += amount;
			}
			else {
				printf("상품 %d의 재고가 부족합니다. (현재 재고 : %d)\n", i + 1, stock[i]);
			}
		}
	}
	else if (option == 2) {
		printf("상품 ID : ");
		scanf("%d", &id);
		if (id < 1 || id > NUM) {
			printf("잘못된 ID입니다.\n");
			clearBuffer();
			return;
		}
		else {
			printf("판매수량 : ");
			scanf("%d", &amount);
			if (amount < 0) {
				printf("잘못된 입력입니다.\n");
				clearBuffer();
				return;
			}
			if (amount <= stock[id - 1]) {
				stock[id - 1] -= amount;
				sell[id - 1] += amount;
			}
			else {
				printf("상품 %d의 재고가 부족합니다. (현재 재고 : %d)\n", id, stock[id - 1]);
			}
		}
	}
	else {
		printf("잘못된 입력입니다.\n");
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

	printf("\[상품 현황]\n");
	printf("재고 수량 : ");
	for (int i = 0; i < NUM; i++) {
		printf("%d ", stock[i]);
	}
	printf("\n총 판매량 : %d (판매율 %.2f%%)\n", totalSell, sellRate);
	printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxID, maxSell);
	printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minID, minSell);

	for (int i = 0; i < NUM; i++) {
		if (stock[i] <= 2) {
			printf("상품 ID %d : 재고부족(%d)\n", i + 1, stock[i]);
		}
	}
}