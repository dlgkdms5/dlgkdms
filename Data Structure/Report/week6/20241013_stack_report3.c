#pragma warning(disable:4996)
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return -1;
}

int evaluatePostfix(char* postfix) {
	Stack s;
	initStack((&s));
	for (int i = 0; postfix[i] != '\0'; i++) {
		char ch = postfix[i];
		if (isdigit(ch)) {
			push(&s, ch - '0');
		}
		else {
			int b = pop(&s);
			int a = pop(&s);
			int result;
			switch (ch) {
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			case '/': result = a / b; break;
			default:
				printf("error...\n");
				exit(1);
			}
			push(&s, result);
		}
	}
	return pop(&s);
}
int infixToPostfix(char* infix, char* postfix) {
	Stack s;
	initStack(&s);
	int j = 0;
	for (int i = 0; infix[i] != '\0'; i++) {
		char ch = infix[i];
		if (isalpha(ch) || isdigit(ch)) {				//피연산자 - 숫자, 문자
			postfix[j++] = ch;
		}
		else if (ch == '(') {		//여는 괄호
			push(&s, ch);
		}
		else if (ch == ')') {		//닫는 괄호
			while (!isEmpty(&s) && peek(&s) != '(') {
				postfix[j++] = pop(&s);
			}
			pop(&s);
		}
		else {						//연산자
			while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
				postfix[j++] = pop(&s);
			}
			push(&s, ch);
		}
	}
	while (!isEmpty(&s))	postfix[j++] = pop(&s);
	postfix[j] = '\0';

	return evaluatePostfix(postfix);

}

int main() {
	char infix[MAX];
	char postfix[MAX];
	int result;
	printf("중위표기식 입력 : ");
	scanf("%s", infix);
	result = infixToPostfix(infix, postfix);
	printf("후위표기식 : %s\n", postfix);
	printf("후위표기식 계산 결과 : %d\n", result);
	return 0;
}
