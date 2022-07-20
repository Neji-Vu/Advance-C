#include "LinkedList/LinkedList.c"

int main(int argc, char const *argv[]){
	node* head = NULL;
	// head = initNode(12);
	for(uint8_t i = 0; i < 5; ++i){
		appendList(&head, i);
	}



	printf("%d\n",getValue(&head, 5));

	return 0;
}