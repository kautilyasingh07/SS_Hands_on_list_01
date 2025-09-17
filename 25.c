/*
====================================================================================================================================
Name: 25.c
Author : KAUTILYA SINGH
Description : 
Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).

Date: 03rd Sept, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
	
	pid_t pid1, pid2, pid3;

	//Create child 1
	pid1 = fork();
	if(pid1 < 0){
		perror("fork failed");
		exit(1);
	}
	else if(pid1 == 0){
		printf("Child one, PID: %d, PPID: %d\n", getpid(), getppid());
		sleep(2);
		exit(1);
	}


	//Create child 2
	pid2 = fork();
	if(pid2 < 0){
		perror("fork failed");
		exit(1);
	}
	else if(pid2 == 0){
		printf("Child two, PID: %d, PPID: %d\n", getpid(), getppid());
		sleep(4);
		exit(2);
	}


	//Create child 3
	pid3 = fork();
	if(pid3 < 0){
		perror("fork failed");
		exit(1);
	}
	else if(pid3 == 0){
		printf("Child three, PID: %d, PPID: %d\n", getpid(), getppid());
		sleep(6);
		exit(3);
	}


	//Parent process
	printf("Parent: PID: %d, Waiting for child 2 (PID: %d)", getpid(), pid2);

	int status;
	pid_t waited_pid = waitpid(pid2, &status, 0); //wait only for child 2
	
	if(waited_pid == -1){
		perror("Waitpid failed");
	}
	else{
		if(WIFEXITED(status)){
			printf("Parent: child %d terminated with exit status %d\n", waited_pid, WEXITSTATUS(status));
		}
	}
	
	//Parent wait for other children(optional, to avoid zombie process)
	while(wait(NULL) > 0);

	printf("Parent: All children have terminated\n");





	return 0;
}


/*
Output:

autilya-Singh:./25
Child two, PID: 19959, PPID: 19957
Child one, PID: 19958, PPID: 19957
Child three, PID: 19960, PPID: 19957
Parent: PID: 19957, Waiting for child 2 (PID: 19959)Parent: child 19959 terminated with exit status 2
Parent: All children have terminated

*/

