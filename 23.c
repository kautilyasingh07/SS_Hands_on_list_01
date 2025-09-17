/*
====================================================================================================================================
Name: 23.c
Author : KAUTILYA SINGH
Description : 
Write a program to create a Zombie state of the running program.

Date: 02nd Sept, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>


int main(){
	pid_t pid = fork();

	if(pid < 0){
		perror("fork failed");
		return 1;
	}
	else if(pid == 0){
		//Child process
		printf("Child process, PID: %d\n", getpid());
		printf("Child exiting...\n");
		return 1;
	}
	else{
		//parent process
		printf("Parent process, PID: %d\n", getpid());
		printf("Child process: %d\n", pid);
		sleep(30); //parent sleep, child become zombie

		printf("Parent process exiting now\n");
	}
	return 0;
}


/*
Output:

Kautilya-Singh:./23
Parent process, PID: 19791
Child process: 19792
Child process, PID: 19792
Child exiting...

Parent process exiting now
Kautilya-Singh:


*/

