/*
====================================================================================================================================
Name: 02.c
Author : KAUTILYA SINGH
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.

Date: 09th Aug, 2025
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>

int main(){

	while(true){
		printf("process running, PID= %d\n",getpid());
		sleep(2);
	}

	return 0;
}



/*
Output:
Kautilya-Singh:ls /proc/15923
arch_status  clear_refs          cpuset   fdinfo             latency    mem         ns             pagemap      sched      smaps_rollup  syscall         uid_map
attr         cmdline             cwd      gid_map            limits     mountinfo   numa_maps      patch_state  schedstat  stack         task            wchan
autogroup    comm                environ  io                 loginuid   mounts      oom_adj        personality  sessionid  stat          timens_offsets
auxv         coredump_filter     exe      ksm_merging_pages  map_files  mountstats  oom_score      projid_map   setgroups  statm         timers
cgroup       cpu_resctrl_groups  fd       ksm_stat           maps       net         oom_score_adj  root         smaps      status        timerslack_ns
Kautilya-Singh:ll /proc/15923



*/
