#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int send_signal(int pid, int signo){
	int ret;
	ret = kill (pid, signo);
	// printf("ret: %d\n", ret);
	return ret;
}

int get_pid(){
	char pidof[128];
	int pid;
	
    FILE *fp = popen("pidof a.out","r");
    fgets(pidof,128,fp);
    printf("%s",pidof);
    pclose(fp);
	pid = atoi(pidof);
	printf("%d",pid);
	return pid;
}

int main(int argc, char *argv[]){
	int pid, signo;
	if(argc != 2){
		fprintf(stderr, "Usage: %s <sig #>\n", argv[0]);
		exit(1);
	}
	
	pid = get_pid();
	signo = atoi(argv[1]);
	send_signal(pid, signo);
	return 0;
}