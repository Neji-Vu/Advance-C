#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

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
void clearList(node**);
void setValue(node**, uint8_t, uint8_t);
uint8_t getValue(node**, uint8_t);

void printList(node*);

#endif