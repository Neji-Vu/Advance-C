#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct LinkedList{
	uint8_t value;
	struct LinkedList* next;
} node;

node* initNode(const uint8_t);
node* changeHead(node*, const uint8_t);
void changeHead1(node**, const uint8_t);
void appendList(node**, const uint8_t);
void insertAfter(node**, const uint8_t, const uint8_t);
void clearHead(node**);
void clearEnd(node**);
void clearAfter(node**, uint8_t);
void setValue(node**, uint8_t, uint8_t);
uint8_t getValue(node**, uint8_t);

void printList(node*);

#endif