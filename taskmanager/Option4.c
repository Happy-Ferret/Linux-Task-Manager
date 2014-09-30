#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void Option4(pid_t MPid)
{

int fatal(char *);
pid_t pid;

int z = 1;
int UsrInput;
int Input2;

while(z == 1)
{

printf ("\nWelcome to the Advanced Controls Section: Choose an Option\n\n ");
printf ("1.  ShutDown the Computer\n");
printf (" 2.  Restart the Computer\n\n");
printf (" 3.  Filter Processes by Username\n");
printf (" 4.  Show Total CPU Usage\n");
printf (" 5.  Show Total Percentage Memory Usage\n");
printf (" 6.  Show Total Virtual Mem Usage\n");
printf (" 7.  Show Total RSS Usage\n");
printf (" 10. Show Total Page Size Usage\n");
printf ("\n 8. Exit to Main Menu\n");
printf (" 9. Exit To Terminal\n\n");

printf ("Your Choice : ");
scanf ("%d", &UsrInput);

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
			execl("/bin/sh", "sh", "Shutdown.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}

		break;

	case 2:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "Reboot.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
		break;

	case 3:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "FilterUser.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}

		break;

	case 4:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "TotalCpu.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}

		break;

	case 5:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "TotalMem.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}

		break;

	case 6:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "TotalVSZ.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}

		break;

	case 7:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "TotalRSS.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}

		break;

	case 10:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "TotalSZ.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}

		break;

	
	case 8:
		z = 0;
		break;

	case 9:
		kill(MPid,9);
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
		printf ("Type 1 To Continue\n");
		printf ("Type 2 To Exit To Main Menu\n");
		printf ("Type 3 To Exit To Terminal\n");
		printf ("\nYour Choice : ");
		scanf ("%d", &Input2);
		
		switch(Input2)
		{
			case 1:
				z = 1;
				break;

			case 2:
				z = 0;
				break;
				
			case 3:
				kill(MPid, 9);
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
				printf ("Again Wrong Input\n");
				printf ("We Can't Let You Use The Program. BYE ! \n\n");
				kill(MPid, 9);
				break;
		}
}

			

} /* End While Loop */

} /* End Option4 */
