#include "Stack.h"

Stack* initStack(uint8_t length){
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->length = length;
	stack->top = -1;
	stack->data = (uint8_t*)malloc(stack->length * sizeof(uint8_t));
	memset(stack->data, '\0', stack->length * sizeof(uint8_t));
	return stack;
}

void clearStack(Stack** stack){
	if(*stack == NULL) return;
	free((*stack)->data);
	free(*stack);
}

bool isEmpty(Stack* stack){
	return stack->top == -1;
}

bool isFull(Stack* stack){
	return stack->top == stack->length - 1;
}

