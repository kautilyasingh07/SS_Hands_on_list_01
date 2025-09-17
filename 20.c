/*
====================================================================================================================================
Name: 20.c
Author : KAUTILYA SINGH
Description : 
Find out the priority of your running program. Modify the priority with nice command.

Date: 30th Aug, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/resource.h>

int main(){
	
	int pid = getpid();

	int prio = getpriority(PRIO_PROCESS, pid);
	printf("PID: %d, Current nice value is: %d\n", pid, prio);

	//increase priority
	int ret = nice(5);
	if(ret == -1){
		perror("ret:");
		return 1;
	}
	
	int newPrio = getpriority(PRIO_PROCESS, pid);
	printf("After nice(5), new nice value is: %d\n", newPrio);
	

	return 0;
}



/*
Output:

Kautilya-Singh:./20
PID: 19460, Current nice value is: 0
After nice(5), new nice value is: 5

*/

