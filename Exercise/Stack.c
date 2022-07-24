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
	return stack->top >= (stack->length - 1);
}

void pushBackStack(Stack* stack, uint8_t value){
	if(stack == NULL) return;
	if(isFull(stack)){
		printf("Stack is full, cannot push.\n");
		return;
	}
	stack->data[++stack->top] = value;
}

// Returns and removes an item from the stack
uint8_t popStack(Stack* stack){
	if(stack == NULL) return '\0';
	if(isEmpty(stack)){
		printf("Stack has not data to pop.\n");
		return '\0';
	}
	uint8_t temp = stack->data[stack->top];
	stack->data[stack->top--] = '\0';
	return temp;
}

// Returns an item from the stack
uint8_t peekStack(Stack* stack){
	if(stack == NULL) return '\0';
	if(isEmpty(stack)){
		printf("Stack has not data to pop.\n");
		return '\0';
	}
	return stack->data[stack->top];
}
