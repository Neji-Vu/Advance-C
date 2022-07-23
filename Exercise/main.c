#include "LinkedList.c"
#include "SortNumbers.c"

#define LOOP(LENGTH) for(uint8_t index = 0; index < (LENGTH); ++index)

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
	printf("=> The comparison is %s\n", compareTwoStrings(firstString, secondString) ? "correct" : "not correct");


	printf( "\n/****************************************************************/\n"
			"/* Sort Numbers                                                 */\n"
			"/****************************************************************/\n"
			);

	uint8_t unsortedArray[7U] = {10U, 35U, 1U, UINT8_MAX, 4U, 26U, 10U};
	uint8_t length = sizeof(unsortedArray) / sizeof(uint8_t);
	// Ascending order (from small to large)
	sortNumbers(unsortedArray, length, ascending);
	printf("Ascending order (from small to large): ");
	LOOP(length){
		printf("%d ", unsortedArray[index]);
	}

	// Descending order (from small to large)
	sortNumbers(unsortedArray, length, descending);
	printf("\nDescending order (from large to small): ");
	LOOP(length){
		printf("%d ", unsortedArray[index]);
	}


	printf( "\n\n****************************************************************/\n"
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