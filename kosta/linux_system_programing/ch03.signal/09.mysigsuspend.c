#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signalHandler(int signo);

int main() 
{ 
    sigset_t set, oldset, newset; 
    struct sigaction act;
	int repeat=1;

    // act.sa_handler = signalHandler;
    // sigemptyset(&act.sa_mask);
    // act.sa_flags = 0;
    // /* SIGINT�� ���� act �ൿ�� �ϵ��� ���� */
    // sigaction(SIGINT, &act, NULL);
	// sigaction(SIGQUIT, &act, NULL);
	
	// signal(SIGINT, signalHandler);
	// signal(SIGQUIT, signalHandler);

    sigemptyset(&set); 
	sigfillset(&newset);
	sigdelset(&newset, SIGINT);
	// sigdelset(&newset, SIGQUIT);
    sigaddset(&set, SIGINT); 
	sigaddset(&set, SIGQUIT);

    /* SIGINT �ñ׳ο� ��� ���� */
    sigprocmask(SIG_BLOCK, &newset, &oldset);
	sigprocmask(SIG_BLOCK, &set, &oldset);
    sleep(1);
	while(repeat != 10){
		/* �ñ׳� ����� oldset�� �����԰� ���ÿ� �ñ׳��� ������ ������ �ߴ� */
		printf("I am running.... waiting for a signal....\n");
		sigsuspend(&oldset);
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
    printf("signal %d received .....\n", signo);
}

// ��ó: http://molrayo.tistory.com/entry/Signal-sigpendingsigsuspend-���� [���α׷�]