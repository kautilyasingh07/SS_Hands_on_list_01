/*
====================================================================================================================================
Name: 16.c
Author : KAUTILYA SINGH
Description : 
Write a program to perform mandatory locking.
    a. Implement write lock
    b. Implement read lock

Date: 25th Aug, 2025    
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h> //For flock
#include<string.h>

void file_lock(int fd, short type){
	
	struct flock lock;

	lock.l_type = type;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	if(type == F_UNLCK){
		fcntl(fd, F_SETLK, &lock);
		printf("process: %d lock released\n", getpid());
	}
	else{
		printf("Process %d, trying to aquire lock: %s\n", getpid(), (type == F_WRLCK) ? "WRITE":"READ");
		fcntl(fd, F_SETLKW, &lock); //F_SETLKW - wait until lock is available
		printf("Process: %d, Aquired %s lock. \n", getpid(), (type == F_WRLCK) ? "WRITE":"READ");
	}

}

int main(int argc, char *argv[]){
	
	struct flock lock;
	char* db_file = "database.txt";

	int fd = open(db_file, O_RDWR | O_CREAT, 0644);

	if(strcmp(argv[1], "r") == 0){
		file_lock(fd, F_RDLCK);
		printf("Reading file...\n");
		sleep(10);
	}
	else if(strcmp(argv[1], "w") == 0){
		file_lock(fd, F_WRLCK);
		printf("Writing file...\n");
		printf("Enter to unlock\n");
		getchar();
//		sleep(10);
	}
	else{
		printf("INVALID OPTION, Enter only <r/w>\n");
		close(fd);
		return 1;
	}
	
	file_lock(fd, F_UNLCK);
	close(fd);

	return 0;
}



/*
Output:

Kautilya-Singh:./16 r
Process 18785, trying to aquire lock: READ
Process: 18785, Aquired READ lock.
Reading file...
process: 18785 lock released


*/
