/*
====================================================================================================================================
Name: 17_01.c
Author : KAUTILYA SINGH
Description : 
Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit.

Date: 26th Aug, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
	struct flock lock;
	int ticket_no;
	char buffer[20];
	char *filename = "ticket.txt";
	
	//Open file if exists else create file
	int fd = open(filename, O_RDWR | O_CREAT ,0644);
	
	//starting ticket number
	sprintf(buffer,"%d\n", 1);
	write(fd, buffer, strlen(buffer));
	
	printf("Ticket system initialize with ticket number: 1\n");

	close(fd);
	return 0;
}


/*
Output:

Kautilya-Singh:./17_01
Ticket system initialize with ticket number: 1

*/

