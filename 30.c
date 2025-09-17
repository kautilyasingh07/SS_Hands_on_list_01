/*
====================================================================================================================================
Name: 30.c
Author : KAUTILYA SINGH
Description : 
Write a program to run a script at a specific time using a Daemon process.
====================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#define TARGET_HOUR 22
#define TARGET_MINUTE 14
#define SCRIPT_PATH "/home/kautilya-singh/class_lab/hands_on_list_01/myscript.sh"
#define LOG_PATH "/home/kautilya-singh/class_lab/hands_on_list_01/daemon_log.log"

int main() {
    // Fork and exit parent so child continues
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    if (pid > 0) {
        exit(0); // parent exits
    }

    // Create new session
    if (setsid() < 0) {
        perror("setsid failed");
        return 1;
    }

    // Go to root dir and reset permissions
    chdir("/");
    umask(0);

    int already_executed = 0; // flag so script runs only once per minute

    while (1) {
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);

        // Check if it's the scheduled time
        if (tm_info->tm_hour == TARGET_HOUR && tm_info->tm_min == TARGET_MINUTE && !already_executed) {
            char command[512];
            snprintf(command, sizeof(command), "%s >> %s 2>&1", SCRIPT_PATH, LOG_PATH);

            system(command); // run script and append logs
            already_executed = 1; // mark as done for this minute
        }

        // Reset flag once minute changes
        if (tm_info->tm_min != TARGET_MINUTE) {
            already_executed = 0;
        }

        sleep(30); // check every 30 seconds
    }

    return 0;
}


/*
Output:

Kautilya-Singh:cat daemon_log.log
[Sun Sep  7 19:35:21 2025
] Daemon started.
[Sun Sep  7 19:36:21 2025
] Running script...
Hello from myscript! Sun Sep  7 07:36:21 PM IST 2025
[Sun Sep  7 19:36:21 2025
] Script finished.
[Sun Sep  7 21:27:02 2025
] Daemon started.


*/


