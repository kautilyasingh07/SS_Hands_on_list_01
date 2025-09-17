/*
====================================================================================================================================
Name: 14.c
Author : KAUTILYA SINGH
Description : 
Write a program to find the type of a file.
    a. Input should be taken from command line.
    b. program should be able to identify any type of a file.

Date: 24th Aug, 2025
====================================================================================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	
	struct stat filestat;
	
	/*
	if(argc < 2){
		printf("No file name passed,  USE: %s <filename>\n", argv[0]);
		return 1;
	}
	*/

	stat(argv[1], &filestat);

	printf("File types -->		");

	switch (filestat.st_mode & S_IFMT){
	
	case S_IFREG:	printf("Regular File\n");	break;
	case S_IFDIR:	printf("Directory file\n");	break;
	case S_IFIFO:	printf("Fifo/pipe file\n");	break;
	case S_IFBLK:	printf("Block Device\n");	break;
	case S_IFCHR:	printf("Character Device\n");	break;
	case S_IFLNK:	printf("System link file\n");	break;
	case S_IFSOCK:	printf("Socket file\n");	break;
	default:	printf("UNKNOWN FILE ??...\n");
	
	return 0;
	
	}
}


/*
Output:

Kautilya-Singh:./14 testfile.txt
File types -->		Regular File


*/
