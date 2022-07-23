#include "LinkedList.h"

node* initNode(const uint8_t value){
	node* ret = (node*)malloc(sizeof(node));
	ret->value = value;
	ret->next = NULL;
	return ret;
}

node* changeHead(node* head, const uint8_t value){
	node* temp = (node*)malloc(sizeof(node));
	temp->next = head;
	temp->value = value;
	return temp;
}

// using pointer to pointer to change the head
void changeHead1(node** head, const uint8_t value){
	node* temp = (node*)malloc(sizeof(node));
	temp->next = *head;
	temp->value = value;
	*head = temp;
}

void appendList(node** head, const uint8_t value){
	node *indexList = *head, *lastNode = initNode(value);
	// when list is empty set last as first
	if(*head == NULL){
		*head = lastNode;
		return;
	}
	// traverse to the end of list
	while (indexList->next != NULL){
		indexList = indexList->next;
	}
	indexList->next = lastNode;
}

void insertAfter(node **head, const uint8_t value, const uint8_t position){
	node *indexList = *head, *atNode = initNode(value);
	// when list is empty set last as first
	if(*head == NULL || position == 0U){
		changeHead1(head, value);
		return;
	}
	uint8_t index = 0U;
	while(indexList != NULL && index != (position - 1U)){
		index++;
		indexList = indexList->next;
	}
	if((position - 1U) > index){
		appendList(head, value);
		return;
	}
	atNode->next = indexList->next;
	indexList->next = atNode;
}

void clearHead(node** head){
	node *temp = *head;
	if(*head == NULL){
		printf("Nothing in list to delete.\n");
		return;
	}
	*head = (*head)->next;
	free(temp);
}

void clearEnd(node** head){
	node *indexList = *head;
	if(*head == NULL || (*head)->next == NULL){
		clearHead(head);
		return;
	}
	while(indexList->next->next != NULL){
		indexList = indexList->next;
	}
	free(indexList->next);
	indexList->next = NULL;
}

void clearAfter(node** head, uint8_t position){
	node *indexList = *head, *freeNode;
	uint8_t index = 0U;
	if(*head == NULL || position == 0U){
		clearHead(head);
		return;
	}
	while(indexList->next != NULL && index != (position - 1U)){
		indexList = indexList->next;
		++index;
	}
	if(indexList->next == NULL || (position - 1U) > index){
		printf("Out of range, cannot delete.\n");
		return;
	}
	freeNode = indexList->next;
	indexList->next = indexList->next->next;
	free(freeNode);
}

void clearList(node** head){
	node *temp = *head;
	while(*head != NULL){
		clearHead(head);
	}
}

void setValue(node** head, uint8_t value, uint8_t position){
	node *indexList = *head;
	uint8_t index = 0U;
	if(*head == NULL){
		printf("Nothing in list to set.\n");
		return;
	}
	while(indexList->next != NULL && index != position){
		indexList = indexList->next;
		++index;
	}
	if(position > index){
		printf("List only has %d element.\n", ++index);
		return;
	}
	indexList->value = value;
}

uint8_t getValue(node** head, uint8_t position){
	node *indexList = *head;
	uint8_t index = 0U;
	if(*head == NULL){
		printf("Nothing in list to get.\n");
		return 0U;
	}
	while(indexList->next != NULL && index != position){
		indexList = indexList->next;
		++index;
	}
	if(position > index){
		printf("List only has %d element.\n", ++index);
		return 0U;
	}
	return indexList->value;
}

// access and print value of list
void printList(node *head){
	uint8_t index = 0U;
	while(head != NULL){
		printf("List[%d] = %d\n", index, head->value);
		index++;
		head = head->next;
	}
}
