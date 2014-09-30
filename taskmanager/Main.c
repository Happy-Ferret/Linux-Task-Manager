#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "Option1.c"
#include "Option2.c"
#include "Option3.c"
#include "Option4.c"

void main(void)
{

int fatal(char *);
pid_t pid;

int z;
int UsrInput;
int Input2;

z = 1;

while(z == 1){

printf ("\nWelcome To Console Task Manager\n");
printf ("Please Select an Option to Continue\n\n");

printf (" 1. Display Running Processes (Default : Sorted by PID)\n"); /* All displays the number of processes */
printf (" 2. Sort Processes\n");
printf (" 3. Kill Processes\n");
printf (" 4. Advanced Controls\n"); /* Processes using maximum memory and other stuff */
printf (" 9. Exit\n\n");

printf ("Your Choice :");
scanf("%d", &UsrInput);
//printf ("%d", UsrInput);

switch(UsrInput)
{

	case 1:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "Option1Log.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
		Option1();
		//exec Option1Log.sh;
		//exec Option1.c;	
		break;		

	case 2:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "Option2Log.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
	
		Option2(getpid());
		//exec Option2Log.sh;
		//exec Option2.c;
		break;

	case 3:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "Option3Log.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
		Option3(getpid());
		//exec Option3Log.sh;
		//exec Option3.c;
		break;

	case 4:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "Option4Log.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
	
		Option4(getpid());
		//exec Option4Log.sh
		//exec Option4.c;
		break;

	case 9:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "ExitLog.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
	
		//exec ExitLog.sh
		z = 0;
		break;

	default:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "WrongLog.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
	
		//exec WrongLog.sh
		printf ("\nWrong Input Provided.\n");
		printf ("Type 1 To Continue. 2 To Exit :");
		scanf ("%d", &Input2);
		if(Input2 == 2){
		z = 0;}
}

}
}

int fatal(char *s)
{
	perror(s);
	exit(1);
}
