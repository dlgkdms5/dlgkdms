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

	printf("[쇼핑몰 관리 프로그램]\n");
	while (1) {
		printf("원하는 메뉴를 선택하세요.(1.입고,2.판매,3.상품현황,4.상품명 입력, 5.종료) : ");
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

void inputstock(int *stock) {
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
			*(stock + i) += amount;
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
			*(stock + id - 1) += amount;
		}
	}
	else {
		printf("잘못된 입력입니다.\n");
		clearBuffer();
		return;
	}
}

void sellProducts(int *stock, int *sell) {
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
			if (amount <= *(stock + i)) {
				*(stock + i) -= amount;
				*(sell + i) += amount;
			}
			else {
				printf("상품 %d의 재고가 부족합니다. (현재 재고 : %d)\n", i + 1, *(stock + i));
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
			if (amount <= *(stock + id - 1)) {
				*(stock + id - 1) -= amount;
				*(sell + id - 1) += amount;
			}
			else {
				printf("상품 %d의 재고가 부족합니다. (현재 재고 : %d)\n", id, *(stock + id - 1));
			}
		}
	}
	else {
		printf("잘못된 입력입니다.\n");
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

	printf("\[상품 현황]\n");
	printf("재고 수량 : ");
	for (int i = 0; i < NUM; i++) {
		printf("%d ", *(stock + i));
	}
	printf("\n총 판매량 : %d (판매율 %.2f%%)\n", totalSell, sellRate);
	printf("가장 많이 판매된 상품 : ID %d, 상품명 : %s , 판매량 %d\n", maxID, name + ((maxID - 1) * 100), maxSell);
	printf("가장 적게 판매된 상품 : ID %d, 상품명 : %s , 판매량 %d\n", minID, name + ((minID - 1) * 100), minSell);

	for (int i = 0; i < NUM; i++) {
		if (*(stock + i) <= 2) {
			printf("상품 ID %d : 상품명 : %s 재고부족(%d)\n", i + 1, name + (i * 100), *(stock + i));
		}
	}
}

void productName(char *name) {

	for (int i = 0; i < NUM; i++) {
		printf("ID %d 상품명 : ", i + 1);
		scanf("%s", name+(i*100));
	}
	return;
}