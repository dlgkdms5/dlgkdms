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

	printf("��ǰ ������ ������ �Է��Ͻÿ� (1~100):");
	scanf("%d", &num);

	if (num < 1 || num>100) {
		printf("1���� 100������ ���� �Է��Ͻÿ�:");
		return 1;
	}

	printf("��ǰ�� ��� ������ �Է��Ͻÿ�:");
	for (int i = 0; i < num; i++) {
		scanf("%d", &stock[i]);
	}

	printf("��ǰ�� �Ǹ� ������ �Է��Ͻÿ�:");
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

	printf("\n������ : ");
	for (int i = 0; i < num; i++) {
		printf("%d", stock[i]);
	}
	printf("\n");

	printf("�� �Ǹŷ� : %d (�Ǹ��� %.2f%%)", totalsales, totalrate);

	printf("\n���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", maxid, maxsales);
	printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", minid, minsales);

	for (int i = 0; i < num; i++) {
		if (stock[i] <= 2) {
			printf("��ǰ ID %d : ������(%d)\n", i + 1, stock[i]);	
		}
	}
	return 0;
}