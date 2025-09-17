/*
====================================================================================================================================
Name: 22.c
Author : KAUTILYA SINGH
Description : 
Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

Date: 02nd Sept, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
	
	char *filename = "fork_output";

	//Open file
	int fd = open(filename, O_RDWR | O_CREAT, 0644);

	//Create child process
	pid_t pid = fork();

	if(pid < 0){
		perror("pid");
		close(fd);
		return 1;
	}
	else if(pid == 0){
		//child process
		char *msg = "Message from child process\n";
		write(fd, msg, strlen(msg));
		printf("Child wrote to file\n");
	}
	else{
		//parent process
		char *msg = "Message from parent process\n";
		write(fd, msg, strlen(msg));
		printf("Parent wrote to file\n");
	}

	close(fd);


	return 0;
}



/*
Output:

Kautilya-Singh:./22
Parent wrote to file
Child wrote to file

Kautilya-Singh:cat fork_output
Message from parent process
Message from child process

*/

