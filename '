/*
====================================================================================================================================
Name: 19.c
Author : KAUTILYA SINGH
Description : 
Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date: 27th Aug, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>

#define ITERATIONS 10000

unsigned long long rdtsc(){
	unsigned int lo, hi;
	__asm__ __volatile__("rdtsc": "=a"(lo), "=d"(hi));
	return ((unsigned long long)hi << 32 ) | lo;
}

int main(){
	
	unsigned long long start, end, total_cycles;
	pid_t pid;
		
	// Record TSC before getpid()
	start = rdtsc();
	
	for(int i =0; i < ITERATIONS; i++)
		pid = getpid();
	
	// Record TSC before getpid()
	end = rdtsc();
	
	unsigned long long avgCycle = (end-start)/ ITERATIONS;
	double freq = 400e6;

	printf("Process ID %d\n", pid);
	printf("Average CPU cycles taken by getpid(): %llu\n", avgCycle);
	printf("%0.2f ns per getpid()\n", (avgCycle/freq)*1e9);
	return 0;
	
}


/*
Output:

Kautilya-Singh:./19
Process ID 19382
Average CPU cycles taken by getpid(): 1180
2950.00 ns per getpid()


*/

