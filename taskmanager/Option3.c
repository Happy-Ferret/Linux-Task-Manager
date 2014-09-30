#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void Option3(pid_t MPid)
{

int fatal(char *);
pid_t pid;

int z = 1;
int UsrInput;
int Input2;

while(z == 1)
{

printf ("\nOn what basis do you want to kill the process ?\n\n");
printf (" 1. Process ID or PID\n");
printf (" 2. Highest Virtual Memory Size\n");
printf (" 3. Highest RSS\n");
printf (" 4. Highest Total Page Size\n");
printf (" 5. Highest Percent CPU Usage\n");
printf (" 6. Highest Percent Main Memory Usage\n");
//printf ("7.  Kill By Process Name\n");
//printf ("10.  
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
			execl("/bin/sh", "sh", "KillPID.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
	
		//exec SaveFilter.sh
		//exec KillPID.sh
		break;

	case 2:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "KillVirtualMem.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
		//exec SaveFilter.sh
		//exec KillVirtualMem.sh
		break;

	case 3:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "KillRSS.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
	
		//exec SaveFilter.sh
		//exec KillRSS.sh
		break;

	case 4:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "KillPageSize.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
	
		//exec SaveFilter.sh
		//exec KillPageSize.sh
		break;

	case 5:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "KillCpu.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
	
		//exec SaveFilter.sh
		//exec KillCpu.sh
		break;

	case 6:
		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "KillMem.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
	
		//exec SaveFilter.sh
		//exec KillMem.sh
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

} /* End Option3 */
