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

	printf("��ǰ ������ ������ �Է��Ͻÿ� (1~100):");
	scanf("%d", &num);

	if (num < 1 || num>100) {
		printf("1���� 100������ ���� �Է��Ͻÿ�:");
		return 1;
	}

	printf("��ǰ�� ��� ������ �Է��Ͻÿ�:");
	for (int i = 0; i < num; i++) {
		scanf("%d", p_stock + i);
	}

	printf("��ǰ�� �Ǹ� ������ �Է��Ͻÿ�:");
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

	printf("\n������ : ");
	for (int i = 0; i < num; i++) {
		printf("%d", *(p_stock + i));
	}
	printf("\n");

	printf("�� �Ǹŷ� : %d (�Ǹ��� %.2f%%)", totalsales, totalrate * 100);

	printf("\n���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", maxid, maxsales);
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", minid, minsales);

	for (int i = 0; i < num; i++) {
		if (*(p_stock + i) <= 2) {
			printf("��ǰ ID %d : ������(%d)\n", i + 1, *(p_stock + i));
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
	printf("������: ");
	for (int i = 0; i < *size; i++) {
		printf("%d ", s[i].in - s[i].out);
		allin += s[i].in;
		allout += s[i].out;
	}
	printf("\n���Ǹŷ�: %.f(�Ǹ��� %0.2f)\n", allout, (allout / allin) * 100);
	for (i = 0, j = 0; i < *size; i++)
		if (m < s[i].out) m = s[i].out, j = i + 1;
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d,�Ǹŷ� %d\n", j, m);
	for (i = 0, j = 0; i < *size; i++)
		if (M > s[i].out) M = s[i].out, j = i + 1;
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d,�Ǹŷ� %d\n", j, M);
	for (i = 0; i < *size; i++)
		if (s[i].in - s[i].out <= 2) printf("��ǰ ID %d : ������(%d)\n", i + 1, s[i].in - s[i].out);
}

int main() {
	int n, id;
	struct system s[101] = { 0 };
	scan(s, &n, &id);
	print(s, &n, &id);
}*/ //���� �ڵ�