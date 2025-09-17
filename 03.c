/*
====================================================================================================================================
Name: 03.c
Author : KAUTILYA SINGH
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call

Date: 09th Aug, 2025
====================================================================================================================================
*/




#include<fcntl.h>  // File control header - for creat()
#include<stdio.h>
#include<unistd.h>  // for close()

int main(){
	
	int fd = creat("create_file.txt", 0644);
	printf("File discripter value: %d \n", fd);


return 0;
}



/*
Output:

Kautilya-Singh:./03
File discripter value: 3

*/
