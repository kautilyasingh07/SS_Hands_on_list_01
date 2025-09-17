/*
====================================================================================================================================
Name: 24.c
Author : KAUTILYA SINGH
Description : 
Write a program to create an orphan process.

Date: 03rd Sept, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>


int main(){
	pid_t pid = fork();

	if(pid < 0){
		perror("pid");
		return 1;
	}
	else if(pid == 0){
		//Child process
		printf("Child process started. PID: %d, Parent PID: %d\n", getpid(), getppid());
		sleep(10);
		printf("Child process after parent exit. PID: %d, New parent PID: %d\n", getpid(), getppid());
		return 1;
	}
	else{
		// Parent process
		printf("Parent process exiting. PID: %d, Child PID: %d\n", getpid(), pid);
		return 1;
	}


	return 0;
}


/*
Output:

Kautilya-Singh:./24
Parent process exiting. PID: 19840, Child PID: 19841
Child process started. PID: 19841, Parent PID: 19840

*/
