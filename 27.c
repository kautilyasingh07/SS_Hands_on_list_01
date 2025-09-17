/*
====================================================================================================================================
Name: 27.c
Author : KAUTILYA SINGH
Description : 
Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp

Date: 06th Sept, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void run_execl(){
	printf("\n=== Using execl ===\n");
	pid_t pid = fork();
	if(pid == 0){
		execl("/bin/ls", "ls", "-Rl", NULL);
		perror("execl failed");
		exit(1);
	}
	else{
		wait(NULL);

	}
}

void run_execlp(){
	printf("\n=== Using execlp ===\n");
	pid_t pid = fork();

	if(pid == 0){
		execlp("ls", "ls", "-Rl", NULL);
		perror("execlp failed");
		exit(1);
	}
	else{
		wait(NULL);
	}

}

void run_execle(){
	printf("\n=== Using execle ===\n");
	pid_t pid = fork();
	if(pid == 0){
		char *envp[] = {"MYVAR=123", NULL};
		execle("/bin/ls", "ls", "-Rl", NULL, envp);
		perror("execle failed");
		exit(1);
	}
	else{
		wait(NULL);
	}
}


void run_execv(){
	printf("\n=== Using execv ===\n");
	pid_t pid = fork();
	if(pid == 0){
		char *args[] = {"ls", "-Rl", NULL};
		execv("/bin/ls", args);
		perror("execv failed");
		exit(1);
	}
	else{
		wait(NULL);
	}
}

void run_execvp(){
	printf("\n=== Using execvp ===\n");
	pid_t pid = fork();
	if(pid == 0){
		char *args[] = {"ls", "-Rl", NULL};
		execvp("ls", args);
		perror("execvp failed");
		exit(1);
	}
	else{
		wait(NULL);
	}
}


int main(){
	
	run_execl();
	run_execlp();
	run_execle();
	run_execv();
	run_execvp();
	return 0;
}

/*
Output:

Kautilya-Singh:./27

=== Using execl ===
.:
total 720
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16024 Sep  7 19:46 01
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1208 Sep  7 20:02 01.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16048 Aug 19 16:40 02
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1514 Sep  7 20:00 02.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16000 Aug 19 17:35 03
-rw-rw-r-- 1 kautilya-singh kautilya-singh   711 Sep  7 20:03 03.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Aug 19 18:41 04
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1092 Sep  7 20:04 04.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Sep  7 20:07 05
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1435 Sep  7 20:11 05.c


=== Using execlp ===
.:
total 720
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16024 Sep  7 19:46 01
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1208 Sep  7 20:02 01.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16048 Aug 19 16:40 02
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1514 Sep  7 20:00 02.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16000 Aug 19 17:35 03
-rw-rw-r-- 1 kautilya-singh kautilya-singh   711 Sep  7 20:03 03.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Aug 19 18:41 04
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1092 Sep  7 20:04 04.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Sep  7 20:07 05
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1435 Sep  7 20:11 05.c


=== Using execle ===
.:
total 720
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16024 Sep  7 19:46 01
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1208 Sep  7 20:02 01.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16048 Aug 19 16:40 02
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1514 Sep  7 20:00 02.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16000 Aug 19 17:35 03
-rw-rw-r-- 1 kautilya-singh kautilya-singh   711 Sep  7 20:03 03.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Aug 19 18:41 04
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1092 Sep  7 20:04 04.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Sep  7 20:07 05
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1435 Sep  7 20:11 05.c


=== Using execv ===
.:
total 720
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16024 Sep  7 19:46 01
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1208 Sep  7 20:02 01.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16048 Aug 19 16:40 02
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1514 Sep  7 20:00 02.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16000 Aug 19 17:35 03
-rw-rw-r-- 1 kautilya-singh kautilya-singh   711 Sep  7 20:03 03.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Aug 19 18:41 04
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1092 Sep  7 20:04 04.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Sep  7 20:07 05
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1435 Sep  7 20:11 05.c


=== Using execvp ===
.:
total 720
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16024 Sep  7 19:46 01
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1208 Sep  7 20:02 01.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16048 Aug 19 16:40 02
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1514 Sep  7 20:00 02.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16000 Aug 19 17:35 03
-rw-rw-r-- 1 kautilya-singh kautilya-singh   711 Sep  7 20:03 03.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Aug 19 18:41 04
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1092 Sep  7 20:04 04.c
-rwxrwxr-x 1 kautilya-singh kautilya-singh 16136 Sep  7 20:07 05
-rw-rw-r-- 1 kautilya-singh kautilya-singh  1435 Sep  7 20:11 05.c


*/


