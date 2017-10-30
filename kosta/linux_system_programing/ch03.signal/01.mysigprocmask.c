#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* void handler(int signo){
	printf("signal %d received...\n", signo);
} */

int main(void) {
	sigset_t set1, set2;

	// signal(SIGINT, handler);
	sigfillset(&set1);	
	sigemptyset(&set2);
	sigaddset(&set2, SIGINT);   

	sigprocmask(SIG_BLOCK, &set1, NULL);    // ��� �ñ׳� ��� ����

	printf("signal block start \n");
	sleep(5);

	sigprocmask(SIG_UNBLOCK, &set2, NULL); // SIGINT �ñ׳� ��Ͽ��� ����
	printf("SIGINT unblocked..... \n");
	
	// pause();
	
	while(1) {    
		printf("Hello Signal\n");    
		sleep(1);  
	}

	return 0;
}
