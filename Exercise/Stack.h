#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack{
	int16_t top;
	uint8_t length;
	uint8_t *data; 
} Stack;

Stack* initStack(uint8_t);
void clearStack(Stack**);
bool isEmpty(Stack*);
bool isFull(Stack*);

void pushBackStack(Stack*, uint8_t);
uint8_t popStack(Stack*);
uint8_t peekStack(Stack*);

#endif