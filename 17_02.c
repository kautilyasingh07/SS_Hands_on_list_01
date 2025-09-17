/*
====================================================================================================================================
Name: 17_02.c
Author : KAUTILYA SINGH
Description : 
Write a program to simulate online ticket reservation. Implement write lock
Write a program, to open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

Date: 27th Aug, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main(){

	char *filename = "ticket.txt";
	char buffer[20];
	struct flock lock;		
	int fd, ticket_no;

	fd = open(filename, O_RDWR);

	//setup write lock
	memset(&lock, 0, sizeof(lock));
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	
	printf("Trying to acquire write lock\n");
	fcntl(fd, F_SETLKW, &lock); //Wait until lock is acquired
	printf("Write lock Acquired! Holding for 10 sec\n");
	sleep(10);

        //Read ticket number
        lseek(fd, 0, SEEK_SET);
        int n = read(fd, buffer, sizeof(buffer));
	ticket_no = atoi(buffer);

	//Increment ticket number
	ticket_no++;
	
	//Write updated ticket number back
	sprintf(buffer, "%d\n", ticket_no);
	ftruncate(fd, 0); //Clear old contents
        lseek(fd, 0, SEEK_SET); 
	write(fd, buffer, strlen(buffer));
	fsync(fd); //ensure write is saved	
	
	printf("Your ticket number is: %d\n", ticket_no);

	//release lock
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Lock released\n");

	close(fd);


	return 0;
}



/*
Output:

Kautilya-Singh:./17_02
Trying to acquire write lock
Write lock Acquired! Holding for 10 sec
Your ticket number is: 2
Lock released

*/
