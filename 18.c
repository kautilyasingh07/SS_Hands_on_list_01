/*
====================================================================================================================================
Name: 18.c
Author : KAUTILYA SINGH
Description : 
Write a program to perform Record locking.
    a. Implement write lock
    b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.

Date: 27th Aug, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

#define RECORD_SIZE 20
#define NUM_RECORDS 3

void lock_record(int fd, int recno, short type){
	struct flock lock;
	memset(&lock , 0, sizeof(lock));
	lock.l_type = type;
	lock.l_whence = SEEK_SET;
	lock.l_start = recno * RECORD_SIZE;
	lock.l_len = RECORD_SIZE;

	printf("Process %d: Trying to acquire %s lock on Record %d\n", getpid(), (type == F_WRLCK) ? "WRITE" : "READ", recno);
	//blocking lock
	fcntl(fd, F_SETLKW, &lock);
	printf("Process %d Acquired %s lock on record: %d\n", getpid(), (type == F_WRLCK) ? "WRITE" : "READ", recno);
}

void unlock_record(int fd, int recno){
	struct flock lock;
	memset(&lock, 0, sizeof(lock));
	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = recno * RECORD_SIZE;
	lock.l_len = RECORD_SIZE;

	fcntl(fd, F_SETLK, &lock);
	printf("Process %d: Release the lock on record %d\n", getpid(), recno);
}

int main(int argc, char *argv[]){
	
	int fd;
	char *filename = "record.txt";

	if(argc != 3){
		printf("Usage: %s <record_no:0-2> <r/w>\n", argv[0]);
		return 1;
	}

	int recno = atoi(argv[1]);	// which record to access
	char mode = argv[2][0];		// 'r' or 'w'
	
	if(recno < 0 || recno >= NUM_RECORDS){
		printf("Invalid record number! Must be between 0 and %d\n", NUM_RECORDS-1);
		return 1;
	}
	
	fd = open(filename, O_RDWR | O_CREAT, 0644);
	

	off_t size = lseek(fd, 0, SEEK_END);
	if(size < RECORD_SIZE * NUM_RECORDS){
		for(int i = 0; i < NUM_RECORDS; i++){
			char buffer[RECORD_SIZE];
			snprintf(buffer, sizeof(buffer), "Record: %d\n", i);
			write(fd, buffer, RECORD_SIZE);
		}
	}
	
	//record lock
	if(mode == 'r'){
		lock_record(fd, recno, F_RDLCK);
		
		//read record
		char buffer[RECORD_SIZE+1];
		lseek(fd, recno*RECORD_SIZE, SEEK_SET);
		read(fd, buffer, RECORD_SIZE);
		buffer[RECORD_SIZE] = '\0';
		printf("Process %d: Read record %d -> %s\n", getpid(), recno, buffer);

	}
	else if(mode == 'w'){
		lock_record(fd, recno, F_WRLCK);

		//write record
		char buffer[RECORD_SIZE];
		snprintf(buffer, sizeof(buffer), "Updated by: %d\n", getpid());
		lseek(fd, recno* RECORD_SIZE, SEEK_SET);
		write(fd, buffer, RECORD_SIZE);
		printf("Process %d, Wrote record in %d\n", getpid(), recno);
	}
	else{
		printf("Invalid mode. Use r/w\n");
		close(fd);
		return 1;
	}
	
	sleep(10);

	unlock_record(fd, recno);

	return 0;
}


/*
Output:

Kautilya-Singh:./18 2 w
Process 19227: Trying to acquire WRITE lock on Record 2
Process 19227 Acquired WRITE lock on record: 2
Process 19227, Wrote record in 2

Process 19227: Release the lock on record 2

*/
