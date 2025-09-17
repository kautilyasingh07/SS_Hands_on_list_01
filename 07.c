/*
====================================================================================================================================
Name: 07.c
Author : KAUTILYA SINGH
Description : Write a program to copy file1 into file2 ($cp file1 file2).

Date: 15th Aug, 2025
====================================================================================================================================
*/


#include<stdio.h>

int main(int argc, char* argv[]){
	

	FILE *src, *dest;
	char ch;
	src = fopen(argv[1], "r");
	dest = fopen(argv[2], "w");
	
	if(argc != 3){
		fprintf(stderr, "Usage: %s <src> <dest>\n", argv[0]);
		return 1;
	}	
	if(src < 0){
		printf("Opening read file error");
	}

	while((ch = fgetc(src)) != EOF){
		fputc(ch, dest);
	}

	fclose(src);
	fclose(dest);

	return 0;
}


/*
Output:

Kautilya-Singh:./07 original.txt file5.txt
Kautilya-Singh:cat original.txt
Hello World
Kautilya-Singh:cat file5.txt
Hello World


*/
