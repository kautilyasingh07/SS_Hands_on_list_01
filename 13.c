/*
====================================================================================================================================
Name: 13.c
Author : KAUTILYA SINGH
Description : 
Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not.

Date: 24th Aug, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>

int main(){

	fd_set readfds;
	struct timeval tv;
	int retval;

	// printf("fd_set: %d\n", fd_set);
	FD_ZERO(&readfds); // clear set
	FD_SET(STDIN_FILENO, &readfds);// add fd 0 to set
	
	tv.tv_sec = 10;
	tv.tv_usec = 0;
	
	printf("Waiting for input (10 sec..)\n");

	retval = select(1, &readfds, NULL, NULL, &tv);
	
	if(retval < 0)
		perror("select()");
	else if(retval == 0)
		printf("Timeout!.. No data entered within 10 seconds\n");
	else if(retval == 1)
		printf("You typed somthing before 10 seconds\n");

	return 0;
}



/*
Output:

Kautilya-Singh:./13
Waiting for input (10 sec..)
No data entered within 10 seconds
Kautilya-Singh:

*/

