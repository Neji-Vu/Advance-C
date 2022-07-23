#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t getLengthString(char string[]){
	uint8_t length = 0U;
	while(string[length] != '\0'){
		++length;
	}
	return length;
}

bool compareTwoStrings(char fristString[], char secondString[]){
	if(getLengthString(fristString) != getLengthString(secondString)) return false;
	uint8_t index = 0U;
	while(fristString[index] != '\0'){
		if(fristString[index] != secondString[index]) return false;
		++index;
	}
	return true;
}

/****************************************************************/
/* Sort Numbers                                                 */
/****************************************************************/

bool ascending(uint8_t firstNumber, uint8_t secondNumber){
	return firstNumber > secondNumber;
}

bool descending(uint8_t firstNumber, uint8_t secondNumber){
	return firstNumber < secondNumber;
}

void swapTwoNumbers(uint8_t *firstNumber, uint8_t *secondNumber){
	if(firstNumber == secondNumber || firstNumber == NULL || secondNumber == NULL) return;
	*firstNumber = *firstNumber + *secondNumber;
	*secondNumber = *firstNumber - *secondNumber;
	*firstNumber = *firstNumber - *secondNumber;
}

void sortNumbers(uint8_t *arr, uint8_t length, bool(*comparison)(uint8_t, uint8_t)){
	uint8_t tempIndex = 0U;
	for(uint8_t index = 0U; index < length - 1U; ++index){
		tempIndex = index;
		for(uint8_t index2 = index + 1U; index2 < length; ++index2){
			if(comparison(arr[tempIndex], arr[index2])){
				tempIndex = index2;
			}
		}
		swapTwoNumbers(&arr[index], &arr[tempIndex]);
	}
}

void printArr(uint8_t *arr, uint8_t length){
	for(uint8_t index = 0U; index < length; ++index){
		printf("%d ", arr[index]);
	}
}