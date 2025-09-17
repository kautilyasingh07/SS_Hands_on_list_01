#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	
	if(argc < 2){
		printf("USE: %s <name>\n", argv[0]);
		return 1;
	}
	printf("Hello, %s, This is a.out speaking.\n", argv[1]);

	return 0;
}
