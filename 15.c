/*
====================================================================================================================================
Name: 15.c
Author : KAUTILYA SINGH
Description : 
Write a program to display the environmental variable of the user (use environ).

Date: 24th Aug, 2025
====================================================================================================================================
*/

#include<stdio.h>

extern char **environ;


int main(){
	char **env = environ;

	while(*env){
		printf("%s\n", *env);
		env++;
	}

	return 0;
}






/*
Output:

Kautilya-Singh:./15
SHELL=/bin/bash
SESSION_MANAGER=local/kautilya-singh-ASUS-TUF-Gaming-F15-FX507ZC4-FX577ZC4:@/tmp/.ICE-unix/2705,unix/kautilya-singh-ASUS-TUF-Gaming-F15-FX507ZC4-FX577ZC4:/tmp/.ICE-unix/2705
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_MENU_PREFIX=gnome-
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
GNOME_SHELL_SESSION_MODE=ubuntu
SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
MEMORY_PRESSURE_WRITE=c29tZSAyMDAwMDAgMjAwMDAwMAA=
XMODIFIERS=@im=ibus
DESKTOP_SESSION=ubuntu
GTK_MODULES=gail:atk-bridge
PWD=/home/kautilya-singh/class_lab/hands_on_list_01
LOGNAME=kautilya-singh
XDG_SESSION_DESKTOP=ubuntu
XDG_SESSION_TYPE=wayland
SYSTEMD_EXEC_PID=2739
XAUTHORITY=/run/user/1000/.mutter-Xwaylandauth.TULKC3
HOME=/home/kautilya-singh
USERNAME=kautilya-singh
IM_CONFIG_PHASE=1
LANG=en_US.UTF-8

*/

