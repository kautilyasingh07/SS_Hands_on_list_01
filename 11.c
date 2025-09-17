/*
====================================================================================================================================
Name: 11.c
Author : KAUTILYA SINGH
Description : 
Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl

Date: 20th Aug, 2025
====================================================================================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[]){
	
	int fd1, fd2;

	char* text1 = "Hello from fd1\n";
        char* text2 = "Hello from fd2\n";

	
	// =====================DUP====================================
	fd1 = open("dup_test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if(fd1 < 0){
		perror("open dup_test.txt");
		return 1;
	}

	fd2 = dup(fd1);  // assign lowest available FD number
	if(fd2 < 0){
		perror("dup");
		return 1;
	}

	// char* text1 = "Hello from fd1\n";
	// char* text2 = "Hello from fd2\n";

	//Write original fd
	if(write(fd1, text1, strlen(text1)) != strlen(text1)){
		perror("fd1 write");
		return 1;
	}

	//Write using duplicated fd
	if(write(fd2, text2, strlen(text2)) != strlen(text2)){
		perror("fd2 write");
		return 1;
	}
	
	printf("Writing with fd : %d\n", fd1);
	printf("Writing with fd : %d\n", fd2);

	close(fd1);
	close(fd2);
	
	// ======================= DUP2 =================================
	fd1 = open("dup2_test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if(fd1 < 0){
		perror("fd1 open");
		return 1;
	}
	
	fd2 = 10;  // Assign 10 as fd
	// fd2 = 1	   Assign 1 to redirect text in file
	if(dup2(fd1, fd2) < 0){	//Specify specific fd
		perror("fd2 dup2");
		return 1;
	}
	
	//Writing original FD
	if(write(fd1, text1, strlen(text1)) != strlen(text1)){
		perror("fd1 write");
		return 1;
	}

	//Writing in assigned fd
	if(write(fd2, text2, strlen(text2)) != strlen(text2)){
		perror("fd2 write");
		return 1;
	}

	printf("Writing with fd: %d\n", fd1);
	printf("Writing with fd: %d\n", fd2);
	
	close(fd1);
	close(fd2);
	

	// ========================== FCNTL ===============================
	fd1 = open("fcntl_dup.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if(fd2 < 0){
		perror("fd open fcntl_dup.txt");
		return 1;
	}
	fd2 = fcntl(fd1, F_DUPFD, 8);
	if(fd2	< 0){
		perror("fd2 fcntl");
		return 1;
	}
	
	//Writing in original fd
	if(write(fd1, text1, strlen(text1)) != strlen(text1)){
		perror("fd1 write");
		return 1;
	}

	//Writing in duplicated fd
	if(write(fd2, text2, strlen(text2)) != strlen(text2)){
		perror("write");
		return 0;
	}
	
	printf("Writing with fd1: %d\n", fd1);
	printf("Writing with fd2: %d\n", fd2);

	close(fd1);
	close(fd2);


	return 0;
}



/*
Output:

Kautilya-Singh:./11
Writing with fd : 3
Writing with fd : 4
Writing with fd: 3
Writing with fd: 10
Writing with fd1: 3
Writing with fd2: 8


*/
