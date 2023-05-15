#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<syslog.h>
#include<signal.h>

#define LOGGING "Start Logging my task = %d\n"

int main()
{
	pid_t pid;
	int x_fd;

	pid = fork();

	if( pid < 0 )			// fork failure handled
		exit(EXIT_FAILURE);
	
	if( pid > 0 )			// parent process exit immediately
		exit(EXIT_SUCCESS);
	
	if( setsid() < 0 )		// to make current process session ledader
		exit(EXIT_FAILURE);

	signal(SIGCHLD, SIG_IGN);
	signal(SIGHUP, SIG_IGN);

		
	pid = fork();

	if( pid < 0 )
		exit(EXIT_FAILURE);

	if( pid > 0 )
	{
		printf("Parent pid = %d\n", getpid());
		exit(EXIT_SUCCESS);
	}

	umask(007);			// set the file permissions for process
	
	chdir("/");			// change current directry to /
	
	for(x_fd = sysconf(_SC_OPEN_MAX) ; x_fd>=0 ; x_fd-- )
	{
		close(x_fd);		// close all fd associated with proceess
	}

	int count = 0 ;
	openlog("Logs", LOG_PID, LOG_USER);
	
	while(1)
	{
		sleep(2);
		syslog(LOG_INFO, LOGGING, count++);
	}

	closelog();
	return 1;
}















/*
int main()
{
	int i = 0 ;
	printf("Deamon Started\n");
	while(1)
	{
		printf("Deamon %d\n", ++i );
		if(i < 345631 * 1.5)
			malloc(1024*2);
		sleep(0.5);
	}
	
	
	return 0;
}
*/
