#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <math.h>
#define WORD	16

void getBiary(char bin[], char str[], int n) {
	for (int i = 0; i < n - strlen(str); i++)
		bin[i] = '0';
	strcat(bin, str);
	return;
}

void complement2(char bin[], int n) {
	for (int i = 0; i < n; i++)
		bin[i] = (bin[i] == '0') ? '1' : '0';
	for (int i = n - 1; i >= 0; i--) {
		if (bin[i] == '0')
			bin[i] = '1';
		else
			bin[i] = '0';
	}
	return;
}

int bin2dec(char bin[], int n) {
	int result = 0;
	if (bin[0] == '1')
		return -1;
	for (int i = 0; i < n; i++)
		result = result * 2 + (bin[i] - '0');
	return result;
}

int main() {
	char input1[100];
	char input2[100];
	char op[10];

	char binary1[WORD + 1] = { 0 };
	char binary2[WORD + 1] = { 0 };

	int result;
	int num1, num2;

	printf("<<<<<input>>>>>>\n");
	gets(input1);
	gets(op);
	gets(input2);
	getBiary(binary1, input1, WORD);
	getBiary(binary2, input2, WORD);

	num1 = bin2dec(binary1, WORD);
	num2 = bin2dec(binary2, WORD);

	switch (op[0]) {
	case '+':result = num1 + num2; break;
	case '-':result = num1 - num2; break;
	case '*':result = num1 * num2; break;
	case '/':result = num1 / num2; break;
	case '%':result = num1 % num2; break;
	default: printf("bad operator...\n");	break;
	}
	printf("%s(%d) %c %s(%d) = %d\n", binary1, num1, op[0], binary2, num2, result);
	return 0;
}
