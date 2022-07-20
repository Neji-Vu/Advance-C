#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t getLengthString(char string[]){
	int length = 0;
	while(string[length] != '\0'){
		length++;
	}
	return length;
}

bool compareTwoString(char fristString[], char secondString[]){
	if(getLengthString(fristString) != getLengthString(secondString)) return false;
	uint8_t index = 0;
	while(fristString[index] != '\0'){
		if(fristString[index] != secondString[index]) return false;
		++index;
	}
	return true;
}

int main(int argc, char const *argv[]){
	char firstString[100];
	char secondString[100];

	printf("Enter the first string: ");
	fgets(firstString, sizeof(firstString), stdin);
	printf("Enter the second string: ");
	fgets(secondString, sizeof(secondString), stdin);
	printf("The comparison is %s\n", compareTwoString(firstString, secondString) ? "correct" : "not correct");

	return 0;
}
