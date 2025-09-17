/*
====================================================================================================================================
Name: 09.c
Author : KAUTILYA SINGH
Description : 
Write a program to print the following information about a given file.
      a. inode
      b. number of hard links
      c. uid
      d. gid
      e. size
      f. block size
      g. number of blocks
      h. time of last access
      i. time of last modification
      j. time of last change

Date: 17th Aug, 2025
====================================================================================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<string.h>

int main(int argc, char** argv){
	struct stat fileStat;
	

        if(argc < 2){
                fprintf(stderr, "Wrong argument!! Use: %s <filename>\n", argv[0]);
                return 1;
        }

	//Print Header row
	printf("%-12s %10s %17s %6s %6s %6s %10s %17s %-25s %-25s %-25s \n",
		"File",
		"inode",
		"num_of_Hard_links",
		"uid",
		"gid",
		"size",
		"block_size",
		"num_of_blocks",
		"last_time_access",
		"last_modification_time",
		"last_chnge_tme"); 

	for(int i = 1; i < argc; i++){
	        if(stat(argv[i], &fileStat) < 0){
        	        perror("stat");
                	return 1;
                }

		
		char *filename = argv[1];
        	char *lta = ctime(&fileStat.st_atime);
	        char *mta = ctime(&fileStat.st_mtime);
        	char *clc = ctime(&fileStat.st_ctime);

	        //Remove trailing '\n'
        	lta[strcspn(lta, "\n")] = '\0';
	        mta[strcspn(mta, "\n")] = '\0';
        	clc[strcspn(clc, "\n")] = '\0';

		//Print all file details
		printf("%-12s %10ld %17ld %6d %6d %6ld %10ld %17ld %-25s %-25s %-25s \n", 
			argv[i], 
			(long)fileStat.st_ino,
		       	(long)fileStat.st_nlink, 
			fileStat.st_uid, 
			fileStat.st_gid,
		       	(long)fileStat.st_size,
		       	(long)fileStat.st_blksize,
			(long)fileStat.st_blocks,
			lta,
			mta,
			clc);
		
	}
	return 0;
}


/*
Output:

Kautilya-Singh:./09 file1.txt file2.txt 
File              inode num_of_Hard_links    uid    gid   size block_size     num_of_blocks last_time_access          last_modification_time    last_chnge_tme            
file1.txt       3670313                 1   1000   1000      0       4096                 0 Tue Aug 19 19:41:43 2025  Tue Aug 19 19:41:43 2025  Tue Aug 19 19:41:43 2025  
file2.txt       3670324                 1   1000   1000      0       4096                 0 Tue Aug 19 19:41:43 2025  Tue Aug 19 19:41:43 2025  Tue Aug 19 19:41:43 2025  
Kautilya-Singh:


*/






