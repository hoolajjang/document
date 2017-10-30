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

    /* SIGINT 시그널에 블록 설정 */
    sigprocmask(SIG_BLOCK, &set, &oldset);
    sleep(1);
	while(repeat != 10){
		/* 시그널 블록을 oldset로 설정함과 동시에 시그널이 도착할 때까지 중단 */
		printf("I am running.... waiting for a signal....\n");
		// sigsuspend(&oldset);
		sigsuspend(&set);
		printf("I received a signal and processed it....\n");
		repeat++;
	}
    /* 시그널 블록을 oldset로 설정함과 동시에 시그널이 도착할 때까지 중단 */
    // sigsuspend(&oldset);
    // exit(0);
	return 0;
}

void signalHandler(int signo)
{
    printf("Hi! signal %d\n", signo);
}

// 출처: http://molrayo.tistory.com/entry/Signal-sigpendingsigsuspend-예제 [프로그램]