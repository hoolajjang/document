#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <syslog.h>

int main(void)
{
	pid_t pid;
	unsigned long cnt=0;

	if((pid = fork()) != 0) exit(0);
	setsid();
	if(chdir("/") !=0 ) {
		perror("chdir");
		exit(1);
	}

	syslog(LOG_INFO|LOG_DAEMON, "Test Daemon Process Start(%d)...\n", getpid());
	while(1) {
		sleep(1);
		syslog(LOG_INFO|LOG_DAEMON, "Test Daemon Process(%d)...\n", ++cnt);
	}

	return 0;
}
