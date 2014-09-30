#include <sys/types.h>
#include <sys/wait.h> /* for wait() */
#include <unistd.h> /* for fork() */
#include <stdio.h> /* for printf() */
#include <stdlib.h> /* for perror() */

int main(void)
{
int fatal(char *);
pid_t pid;

switch(pid = fork())
{
case -1:
	fatal("fork failed");
	break;
case 0:
	/* child process calls exec */
	execl("/bin/sh", "sh", "PrintFilter.sh", (char *)0);
	fatal("exec failed");
	break;
default:
	
	/* until child process finishes */
	wait((int *)0);
	printf("Hi\n");
	break;
}
}
int fatal(char *s)
{
	perror(s);
	exit(1);
}









