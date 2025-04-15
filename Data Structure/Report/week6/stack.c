#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(Stack* s) {
	s->top = -1;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

void push(Stack* s, int value) {
	if (s->top >= MAX - 1) {
		printf("Stack overflow! Cannot push %d\n", value);
		return;
	}
	s->data[++(s->top)] = value;
}

int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stacl underflow! Cannot pop\n");
		return -1;
	}
	return s->data[(s->top)--];
}

int peek(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty! Cannot peek\n");
		return -1;
	}
	return s->data[s->top];
}

void display(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty!\n");
		return;
	}
	printf("Stack contents : ");
}
