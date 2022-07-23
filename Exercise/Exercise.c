#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t getLengthString(char string[]){
	uint8_t length = 0U;
	while(string[length] != '\0'){
		length++;
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


