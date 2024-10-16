#include <stdio.h>

int main()
{
	int id;
	int stock[100] = { 0 };
	int sold[100] = { 0 };
	int num, total;
	int totalsales = 0;
	float totalrate = 0.0;
	int maxsales = -1, minsales = 101;	
	int maxid = -1, minid = -1;

	printf("상품 종류의 갯수를 입력하시오 (1~100):");
	scanf("%d", &num);

	if (num < 1 || num>100) {
		printf("1부터 100까지의 수를 입력하시오:");
		return 1;
	}

	printf("상품별 재고 수량을 입력하시오:");
	for (int i = 0; i < num; i++) {
		scanf("%d", &stock[i]);
	}

	printf("상품별 판매 수량을 입력하시오:");
	for (int i = 0; i < num; i++) {
		scanf("%d", &sold[i]);
		stock[i] -= sold[i];
		
		totalsales += sold[i];

		if (sold[i] > maxsales) {
			maxsales = sold[i];
			maxid = i + 1;
		}
		if (sold[i] < minsales) {
			minsales = sold[i];
			minid = i + 1;
		}
	}

	int totalstock = 0;
	for (int i = 0; i < num; i++) {
		totalstock += (stock[i] + sold[i]);
	}
	totalrate = ((float)totalsales / totalstock);

	printf("\n재고수량 : ");
	for (int i = 0; i < num; i++) {
		printf("%d", stock[i]);
	}
	printf("\n");

	printf("총 판매량 : %d (판매율 %.2f%%)", totalsales, totalrate);

	printf("\n가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxid, maxsales);
	printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minid, minsales);

	for (int i = 0; i < num; i++) {
		if (stock[i] <= 2) {
			printf("상품 ID %d : 재고부족(%d)\n", i + 1, stock[i]);	
		}
	}
	return 0;
}