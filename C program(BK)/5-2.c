#include <stdio.h>

int main() {
	char input[200] = "";
	int count[20] = { 0 };
	int ch;
	int i = 0;
	while ((ch = getchar()) != EOF)
		input[i++] = ch;
	i = 0;
	while (input[i] != '\0') {
		if (input[i] >= 'a' && input[i] <= 'z')
			count[input[i] - 'a']++;
		i++;
	}
	printf("�Է¹��ڿ� : %s\n", input);
	for (i = 0; i < 26; i++)
		printf("%c ����Ƚ�� : %d\n", 'a' + i, count[i]);
	return 0;
}