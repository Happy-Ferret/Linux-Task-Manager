#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
pid_t pid;

switch(pid == fork())
{

case -1:
	printf ("Maa Chudao");
	break;

case 0:
	execl("/bin/ls", "ls","-l", (char *) 0);
	break;

default:
	wait((int *)0);
	printf ("Hi\n");
	exit(0);	

}

}
