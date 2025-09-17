/*
====================================================================================================================================
Name: 30.c
Author : KAUTILYA SINGH
Description : 
Write a program to run a script at a specific time using a Daemon process.

Date: 07th Sept, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<time.h>

#define TARGET_HOUR 19
#define TARGET_MINUTE 36
#define SCRIPT_PATH "/home/kautilya-singh/class_lab/hands_on_list_01/myscript.sh"
#define LOG_PATH "/home/kautilya-singh/class_lab/hands_on_list_01/daemon_log.log"

void create_daemon(){
	pid_t pid = fork();

	if(pid < 0){
		perror("fork failed");
		exit(1);
	}

	if(pid > 0){
		//Parent exits, child becomes daemon
		exit(0);
	}
	if(setsid() < 0){
		perror("setside failed");
		exit(1);
	}
	umask(0);
}

void log_message(const char *message) {
    FILE *f = fopen(LOG_PATH, "a");
    if (f) {
        time_t now = time(NULL);
        fprintf(f, "[%s] %s\n", ctime(&now), message);
        fclose(f);
    }
}


int main(){

    create_daemon();

    log_message("Daemon started.");

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == TARGET_HOUR && t->tm_min == TARGET_MINUTE) {
            char command[512];
            snprintf(command, sizeof(command), "%s >> %s 2>&1", SCRIPT_PATH, LOG_PATH);
            log_message("Running script...");
            system(command); // Run your script
            log_message("Script finished.");
            sleep(60); // Prevent multiple executions in the same minute
        }

        sleep(30); // Check every 30 seconds
    }


	return 0;
}
