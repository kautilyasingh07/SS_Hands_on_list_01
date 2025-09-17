/*
====================================================================================================================================
Name: 06.c
Author : KAUTILYA SINGH
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

Date: 15th Aug, 2025
====================================================================================================================================
*/


#include<unistd.h>


int main(){
	
	int fd = 0; // for STDIN
	char buffer[500];

	int n=read(fd, buffer,sizeof(buffer));
      	write(1,buffer,n);	


	return 0;
}




/*
Output:

Kautilya-Singh:./06
HELLO
HELLO

*/
