/*
====================================================================================================================================
Name: 05.c
Author : KAUTILYA SINGH
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.

Date: 10th Aug, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main(){
	const char *filenames[5]={
				"file1.txt", 
				"file2.txt", 
				"file3.txt", 
				"file4.txt", 
				"file5.txt"
				};

	int fds[5];

	for(int i = 0; i < 5; i++){
		fds[i]=open(filenames[i], O_CREAT | O_RDWR, 0644);

		if(fds[i] == -1){
			printf("Failed to open, %s, %s\n", filenames[i], strerror(errno));
			exit(1);
		}
		printf("File opened Successfully!, filename=%s, fd=%d\n", filenames[i], fds[i]);
	}
	
	while(1);
return 0;
}


/*
Output:

Kautilya-Singh:./05 &
[1] 16533
Kautilya-Singh:File opened Successfully!, filename=file1.txt, fd=3
File opened Successfully!, filename=file2.txt, fd=4
File opened Successfully!, filename=file3.txt, fd=5
File opened Successfully!, filename=file4.txt, fd=6
File opened Successfully!, filename=file5.txt, fd=7



Kautilya-Singh:ls /proc/16533/fd 
0  1  2  3  4  5  6  7

*/











