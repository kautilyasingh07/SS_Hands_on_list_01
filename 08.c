/*
====================================================================================================================================
Name: 08.c
Author : KAUTILYA SINGH
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.

Date: 15th Aug, 2025
====================================================================================================================================
*/

#include<stdio.h>

#define MAXLINE 1024 // Maxium line in buffer


int main(int argc, char** argv){
	FILE *fp;
	char line[MAXLINE];
	int ch;
        int i = 0;
	
	if(argc != 2){
		printf("Wrong argument! Use: %s <filename>\n", argv[0]);
		return 1;
	}
	
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Oops, can't Open File\n");
		return 1;
	}

	//Read line by line
	while((ch = fgetc(fp)) != EOF){
		if(ch == '\n'){
			line[i] = '\0';
			printf("%s\n", line);
			i = 0;	
		}
		else{
			line[i++] = ch;
		}
	}
	
	//Handle last line if it is not terminating with '\n'
	if(i > 0){
		line[i] = '\0';
		printf("%s\n", line);
	}
	
	fclose(fp);

	return 0;
}


/*
Output:

Kautilya-Singh:./08 file3
Hello How are you
Do we want to do this work?


*/

