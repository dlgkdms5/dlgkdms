#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int score[10];
	int sum = 0;
	double average;

	for (int i = 0; i < 10; i++) {
		printf("%d��° �л� ������ �Է��Ͻÿ� : ", i+1);
		scanf("%d", &score[i]);
		sum += score[i];
	}

	average = sum / 10.0;
	printf("10���� �л� �� ���� : %d\n", sum);
	printf("10���� �л� ��� ���� : %.2f\n", average);

}