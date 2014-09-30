#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void Option2(pid_t MPid)
{

int fatal(char *);
pid_t pid;

int z = 1;
int UsrInput;
int Input2;

while(z == 1)
{

printf ("\nOn what basis do you want to sort the processes ?\n\n");
printf (" 1. User\n");
printf (" 2. Virtual Memory Size\n");
printf (" 3. RSS\n");
printf (" 4. Total Page Size\n");
printf (" 5. Percent CPU Usage\n");
printf (" 6. Percent Main Memory Usage\n");
printf (" 7. Sort Alphabetically by Process Name\n");
printf ("\n 8. Exit to Main Menu\n");
printf (" 9. Exit To Terminal\n\n");

printf ("Your Choice : ");
scanf ("%d", &UsrInput);

switch(UsrInput)
{

	case 1:
		
		//pid_t pid;

		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "SortByUser.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
						
		//exec SortByUser.sh
		break;

	case 2:
		//int fatal(char *);
		//pid_t pid;

		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "SortByVirtualSize.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
	
		//exec SortByVirtualSize.sh
		break;

	case 3:
		//int fatal(char *);
		//pid_t pid;

		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "SortByRSS.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
	
		//exec SortByRSS.sh
		break;

	case 4:	
		//int fatal(char *);
		//pid_t pid;

		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "SortByPageSize.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
		//exec SortByPageSize.sh
		break;

	case 5:
		//int fatal(char *);
		//pid_t pid;

		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "SortByCpu.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
	
		//exec SortByCpu.sh
		break;

	case 6:
		//int fatal(char *);
		//pid_t pid;

		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "SortByMemUsage.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
		
		//exec SortByMemUsage.sh
		break;

	case 7:
		//int fatal(char *);
		//pid_t pid;

		switch(pid = fork())
		{
		case -1:
			fatal("fork failed");
			break;
		case 0:
			/* child process calls exec */
			execl("/bin/sh", "sh", "SortByCommand.sh", (char *)0);
			fatal("exec failed");
			break;
		default:
			
			/* until child process finishes */
			wait((int *)0);
			sleep(1);
			break;
		}
		
	
		//exec SortByCommand.sh
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
} /* End Switch */
			

} /* End While Loop */

} /* End Option2 */	
