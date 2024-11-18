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

	int* p_stock = stock;
	int* p_sold = sold;

	printf("상품 종류의 갯수를 입력하시오 (1~100):");
	scanf("%d", &num);

	if (num < 1 || num>100) {
		printf("1부터 100까지의 수를 입력하시오:");
		return 1;
	}

	printf("상품별 재고 수량을 입력하시오:");
	for (int i = 0; i < num; i++) {
		scanf("%d", p_stock + i);
	}

	printf("상품별 판매 수량을 입력하시오:");
	for (int i = 0; i < num; i++) {
		scanf("%d", p_sold + i);
		*(p_stock + i) -= *(p_sold + i);
		
		totalsales += *(p_sold + i);

		if (*(p_sold + i) > maxsales) {
			maxsales = *(p_sold + i);
			maxid = i + 1;
		}
		if (*(p_sold + i) < minsales) {
			minsales = *(p_sold + i);
			minid = i + 1;
		}
	}

	int totalstock = 0;
	for (int i = 0; i < num; i++) {
		totalstock += (*(p_stock + i) + *(p_sold + i));
	}
	totalrate = ((float)totalsales / totalstock);

	printf("\n재고수량 : ");
	for (int i = 0; i < num; i++) {
		printf("%d", *(p_stock + i));
	}
	printf("\n");

	printf("총 판매량 : %d (판매율 %.2f%%)", totalsales, totalrate * 100);

	printf("\n가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxid, maxsales);
	printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minid, minsales);

	for (int i = 0; i < num; i++) {
		if (*(p_stock + i) <= 2) {
			printf("상품 ID %d : 재고부족(%d)\n", i + 1, *(p_stock + i));
		}
	}
	return 0;
}

/*#pragma warning(disable:4996)
#include <stdio.h>

typedef struct system {
	int in;
	int out;
};

void scan(struct system* s, int* size, int* id) {
	scanf("%d", size);
	for (int i = 0; i < *size; i++) scanf("%d", &s[i].in);
	for (int i = 0; i < *size; i++) scanf("%d", &s[i].out);
}

void print(struct system* s, int* size, int* id) {
	double allout = 0, allin = 0;
	int i, j, m = 0, M = 100;
	printf("재고수량: ");
	for (int i = 0; i < *size; i++) {
		printf("%d ", s[i].in - s[i].out);
		allin += s[i].in;
		allout += s[i].out;
	}
	printf("\n총판매량: %.f(판매율 %0.2f)\n", allout, (allout / allin) * 100);
	for (i = 0, j = 0; i < *size; i++)
		if (m < s[i].out) m = s[i].out, j = i + 1;
	printf("가장 많이 판매된 상품 : ID %d,판매량 %d\n", j, m);
	for (i = 0, j = 0; i < *size; i++)
		if (M > s[i].out) M = s[i].out, j = i + 1;
	printf("가장 적게 판매된 상품 : ID %d,판매량 %d\n", j, M);
	for (i = 0; i < *size; i++)
		if (s[i].in - s[i].out <= 2) printf("상품 ID %d : 재고부족(%d)\n", i + 1, s[i].in - s[i].out);
}

int main() {
	int n, id;
	struct system s[101] = { 0 };
	scan(s, &n, &id);
	print(s, &n, &id);
}*/ //현우 코드