#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signalHandler(int signo);

int main() 
{ 
    sigset_t set, oldset; 
    struct sigaction act;
	int repeat=1;

	// signal(SIGINT, signalHandler);
	// signal(SIGQUIT, signalHandler);

    sigemptyset(&set); 
    sigaddset(&set, SIGINT); 
	sigaddset(&set, SIGQUIT);

    /* SIGINT �ñ׳ο� ��� ���� */
    sigprocmask(SIG_BLOCK, &set, &oldset);
    sleep(1);
	while(repeat != 10){
		/* �ñ׳� ����� oldset�� �����԰� ���ÿ� �ñ׳��� ������ ������ �ߴ� */
		printf("I am running.... waiting for a signal....\n");
		// sigsuspend(&oldset);
		sigsuspend(&set);
		printf("I received a signal and processed it....\n");
		repeat++;
	}
    /* �ñ׳� ����� oldset�� �����԰� ���ÿ� �ñ׳��� ������ ������ �ߴ� */
    // sigsuspend(&oldset);
    // exit(0);
	return 0;
}

void signalHandler(int signo)
{
    printf("Hi! signal %d\n", signo);
}

// ��ó: http://molrayo.tistory.com/entry/Signal-sigpendingsigsuspend-���� [���α׷�]