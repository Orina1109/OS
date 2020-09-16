#include <pthread.h>
#include <stdio.h>

void* thread_func(void* number)
{
	int n = (int)number;
	printf("thread %d is completed\n", n);
	pthread_exit(0);
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		pthread_t tid;
		printf("thread %d is created\n", i);
		pthread_create(&tid, NULL, thread_func, i);
		pthread_join(tid, NULL);
	}
}