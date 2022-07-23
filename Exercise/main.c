#include "LinkedList.c"
#include "Exercise.c"

int main(int argc, char const *argv[]){

	printf( "/****************************************************************/\n"
			"/* Compare two strings                                          */\n"
			"/****************************************************************/\n"
			);
			
	char firstString[100U];
	char secondString[100U];

	printf("Enter the first string: ");
	fgets(firstString, sizeof(firstString), stdin);
	printf("Enter the second string: ");
	fgets(secondString, sizeof(secondString), stdin);
	printf("=> The comparison is %s\n\n", compareTwoStrings(firstString, secondString) ? "correct" : "not correct");


	printf( "/****************************************************************/\n"
			"/* Linked List                                                  */\n"
			"/****************************************************************/\n"
			);

	node* head = NULL;
	for(uint8_t index = 0U; index < 5U; ++index){
		appendList(&head, index);
	}

	changeHead1(&head, 10U);
	changeHead1(&head, 20U);
	appendList(&head, 50U);
	insertAfter(&head, 30U, 1U);

	setValue(&head, 255U, 3U);
	printf("Value at index %d is: %d\n", 3U, getValue(&head, 3U));

	printList(head);

	clearList(&head);
	printf("All element in list are clear: head = %x\n", head);

	return 0U;
}