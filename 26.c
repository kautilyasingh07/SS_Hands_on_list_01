/*
====================================================================================================================================
Name: 26.c
Author : KAUTILYA SINGH
Description : 
Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Date: 06th Sept, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	
	pid_t pid = fork();

	if(pid < 0){
		perror("fork failed");
		exit(1);
	}
	else if(pid == 0){
		//chil process: Execute other program
		
		//execlp(filename, arg0, arg1, arg2, ...,NULL);
		execlp("./a.out", "./a.out", "Kautilya", NULL);

		perror("execlp failed");
		exit(1);
	}
	else{
		//Parent process
		int status;
		waitpid(pid, &status, 0);
		if(WIFEXITED(status)){
			printf("Parent: child exited with status %d\n", WEXITSTATUS(status));
		}
	}
	return 0;
}





/*
Output:

Kautilya-Singh:./26
Hello, Kautilya, This is a.out speaking.
Parent: child exited with status 0
Kautilya-Singh:

*/

