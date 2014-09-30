#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 

void Option1(void)
{
int fatal(char *);
pid_t pid;

switch(pid = fork())
{
case -1:
	fatal("fork failed");
	break;
case 0:
	execl("/bin/sh", "sh", "PrintFilter.sh", (char *)0);
	fatal("exec failed");
	break;
default:
	wait((int *)0);
	sleep(1);
	break;
}
}










