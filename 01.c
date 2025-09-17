/*
====================================================================================================================================
Name: 01.c
Author : KAUTILYA SINGH
Description : Write a c, ANSI-style program to Create the following types of a files using (i) shell command (ii) system call
	a. soft link (symlink system call)
	b. hard link (link system call)
	c. FIFO (mkfifo Library Function or mknod system call)

Date: 07th Aug, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(void){

	// create hardlink of a file
	link("original.txt", "hardlink_with_c.txt");

	// Create softlink of a file
	symlink("original.txt", "softlink_with_c.txt");
	
	// Create fifo file
	mkfifo("myfifo",0666);

	return 0;
}

/*
Output:

Kautilya-Singh:ll *link_with_c.txt
-rw-rw-r-- 2 kautilya-singh kautilya-singh 12 Aug 19 14:45 hardlink_with_c.txt
lrwxrwxrwx 1 kautilya-singh kautilya-singh 12 Aug 19 14:52 softlink_with_c.txt -> original.txt
Kautilya-Singh:ll myfifo
prw-rw-r-- 1 kautilya-singh kautilya-singh 0 Aug 19 15:57 myfifo|
Kautilya-Singh:


*/
