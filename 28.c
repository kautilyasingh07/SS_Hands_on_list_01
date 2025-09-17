/*
====================================================================================================================================
Name: 28.c
Author : KAUTILYA SINGH
Description : 
Write a program to get maximum and minimum real time priority.
Date: 07th Sept, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<sched.h>

int main(){
	
	int max_fifo = sched_get_priority_max(SCHED_FIFO);
	int min_fifo = sched_get_priority_min(SCHED_FIFO);

	int max_rr = sched_get_priority_max(SCHED_RR);
	int min_rr = sched_get_priority_min(SCHED_RR);

	printf("SCHED_FIFO: min= %d, max = %d\n", min_fifo, max_fifo);
	printf("SCHED_rr: min= %d, max= %d\n", min_rr, max_rr);

	return 0;
}

/*
Output:

Kautilya-Singh:./28
SCHED_FIFO: min= 1, max = 99
SCHED_rr: min= 1, max= 99

*/
