/*
====================================================================================================================================
Name: 12.c
Author : KAUTILYA SINGH
Description : 
Write a program to find out the opening mode of a file. Use fcntl.

Date: 20th Aug, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd, flag;

	fd= open("testmode.txt", O_CREAT | O_WRONLY, 0644);
	
	if(fd < 0){
		perror("fd open");
		return 1;
	}
	
	flag = fcntl(fd, F_GETFL);
	
	if(flag < 0){
		perror("fcntl");
		close(fd);
		return 1;
	}
	

	printf("Fd: %d, Flag_d: %d, Flag_x: %x, access_mode: %x\n", fd, flag, flag, O_ACCMODE);
	int accmode = flag & O_ACCMODE; // O_ACCMODE stores 3 in hex

	if(accmode == O_RDONLY)
		printf("READ MODE\n");
	else if(accmode == O_WRONLY)
		printf("WRITE MODE\n");
	else if(accmode == O_RDWR)
		printf("READ AND WRITE MODE\n");
	
	close(fd);

	return 0;

}



/*
Output:

Kautilya-Singh:./12
Fd: 3, Flag_d: 32769, Flag_x: 8001, access_mode: 3
WRITE MODE

*/

