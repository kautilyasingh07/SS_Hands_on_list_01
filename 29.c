/*
====================================================================================================================================
Name: 29.c
Author : KAUTILYA SINGH
Description : 
Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

Date: 07th Sept, 2025
====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

void print_policy(int policy) {
    switch(policy) {
        case SCHED_OTHER:
            printf("Current policy: SCHED_OTHER (default)\n");
            break;
        case SCHED_FIFO:
            printf("Current policy: SCHED_FIFO (real-time FIFO)\n");
            break;
        case SCHED_RR:
            printf("Current policy: SCHED_RR (real-time Round-Robin)\n");
            break;
        default:
            printf("Current policy: UNKNOWN\n");
    }
}

int main() {
    pid_t pid = getpid();  // get current process id

    // Get current scheduling policy
    int policy = sched_getscheduler(pid);
    if(policy == -1) {
        perror("sched_getscheduler failed");
        exit(1);
    }
    print_policy(policy);

    // Set new scheduling policy
    struct sched_param param;
    param.sched_priority = 10; // priority 1-99 for real-time policies

    printf("Changing policy to SCHED_FIFO...\n");
    if(sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler SCHED_FIFO failed");
    } else {
        policy = sched_getscheduler(pid);
        print_policy(policy);
    }

    printf("Changing policy to SCHED_RR...\n");
    param.sched_priority = 20;
    if(sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler SCHED_RR failed");
    } else {
        policy = sched_getscheduler(pid);
        print_policy(policy);
    }

    return 0;
}


/*
Output:

Kautilya-Singh:sudo ./29
[sudo] password for kautilya-singh:
Current policy: SCHED_OTHER (default)
Changing policy to SCHED_FIFO...
Current policy: SCHED_FIFO (real-time FIFO)
Changing policy to SCHED_RR...
Current policy: SCHED_RR (real-time Round-Robin)
Kautilya-Singh:

*/

