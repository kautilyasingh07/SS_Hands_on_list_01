/*
====================================================================================================================================
Name: 21.c
Author : KAUTILYA SINGH
Description : 
Write a program, call fork and print the parent and child process id.

Date: 30th Aug, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid;

	pid = fork();

	if(pid < 0){
		perror("fork failed\n");
		return 1;
	}
	else if(pid == 0){
		//child process
		printf("Child process, my process id: %d, Parent process id: %d\n", getpid(), getppid());
	}
	else{
		//parent process
		printf("Parent process, my process id: %d, Parent process id: %d\n", getpid(), getppid());
		wait(NULL);
	}
	return 0;
}


/*
Output:

Kautilya-Singh:./21
Parent process, my process id: 19558, Parent process id: 18735
Child process, my process id: 19559, Parent process id: 19558

*/

