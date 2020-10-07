#include <sys/resource.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
	
	//top:
	//top shows that this program uses memory time every second
	//it is becouse every second the very memory-intensive task is running
	struct rusage usage;
	for (int i = 0; i < 10; ++i)
	{
		void* mem = malloc(1024*1024*10);
		memset(mem, 0, 1024*1024*10);
		getrusage(RUSAGE_SELF, &usage);
		printf("CPU time: %ld.%lds, page faults: %ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec, usage.ru_majflt);
		sleep(1);
		free(mem);
	}
}