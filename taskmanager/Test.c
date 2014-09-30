#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

void main(void)
{

printf ("The Pid Is : %d",getpid());

kill(17502, 9);

}
