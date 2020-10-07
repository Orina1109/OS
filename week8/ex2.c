#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	
	//top:
	//top shows that this program uses memory time every second
	//it is becouse every second the very memory-intensive task is running
	for (int i = 0; i < 10; ++i)
	{
		void* mem = malloc(1024*1024*10);
		memset(mem, 0, 1024*1024*10);
		sleep(1);
		free(mem);
	}
}