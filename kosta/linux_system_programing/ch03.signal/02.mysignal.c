#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void handler(int signo){
	printf("Control C Signal received ~~~~%d\n", signo);
}

int main(){
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	signal(SIGSTOP, handler);
	// signal(SIGINT, SIG_IGN);
	// signal(SIGINT, SIG_DFL);
	while(1){
		printf("signal test\n");
		sleep(1);
	}
	
	return 0;
}