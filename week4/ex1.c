#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid = fork();
	switch(pid)
	{
		case 0: //child process
			printf("Hello from parent %d\n", getppid());
			printf("Hello from child %d\n", getpid());
	}
}