/*
====================================================================================================================================
Name: 10.c
Author : KAUTILYA SINGH
Description : 
Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
    a. check the return value of lseek
    b. open the file with od and check the empty spaces in between the data.

Date: 18th Aug, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){

	int fd;
	char *buf1 = "ABCDEFGHIJ";
	char *buf2 = "1234567890";

	fd = open("testfile.txt", O_CREAT | O_RDWR, 0644);
	if(fd <0){
		perror("open");
		return 1;
	}

	//Write first 10 bytes
	if(write(fd, buf1, 10) != 10){
		perror("write buf1");
		return 1;
		}

	//Move file pointer ahead by 10 bytes
	off_t pos = lseek(fd, 10, SEEK_CUR);
	if(pos == (off_t)-1){
		perror("lseek");
		return 1;
	}
	printf("file pointer moved to position: %ld\n", pos);

	//Write second 10 bytes
	if(write(fd, buf2, 10) != 10){
		perror("write buf2");
		return 1;
	}

	close(fd);

	return 0;
}


/*
Output:

Kautilya-Singh:./10
file pointer moved to position: 20
Kautilya-Singh:od -c testfile.txt
0000000   A   B   C   D   E   F   G   H   I   J  \n  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   1   2   3   4   5   6   7   8   9   0  \n
0000037

*/

