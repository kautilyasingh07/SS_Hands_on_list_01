/*
====================================================================================================================================
Name: 04.c
Author : KAUTILYA SINGH
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.

Date: 10th Aug, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main(){
	
	const char *filename = "open_file1.txt";
	
	//Open fle with read-write mode
	int fd = open(filename, O_RDWR);
	
	if(fd == -1){
		printf("No file exist\n");
	}
	else{
		printf("File open successfully, FD= %d\n", fd);
		close(fd);
	}

	fd = open(filename, O_CREAT | O_EXCL, 0644);
	if(fd == -1){
		if(errno == EEXIST)
			printf("File already exist\n");
		else
			printf("File open failed\n");
	}
	else{
		printf("File opened, FD= %d\n", fd);
	}
	// printf("fd = %d", fd);	

return 0;
}



/*
Output:

Kautilya-Singh:./04
File open successfully, FD= 3
File already exist
Kautilya-Singh:

*/





