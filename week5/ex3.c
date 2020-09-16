#include <pthread.h>
#include <stdio.h>

int buffer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int current = 0;
int turn = 0;

void* consumer(void* arg)
{
	while (1)
	{
		if (turn)
		{
			if (current >= 0)
			{
				buffer[current] = 0;
				current--;
			}
			else 
			{
				turn = 0;
				current++;
			}
		}
	}
}

void* producer(void* arg)
{
	while (1)
	{
		if (!turn)
		{
			if (current < 10) 
			{
				buffer[current] = 1;
				current++;
			}
			else 
			{
				turn = 1;
				current--;
			}
		}
	}
}

int main()
{
	pthread_t tid1, tid2;
	pthread_create(tid1, NULL, producer, NULL);
	pthread_create(tid2, NULL, consumer, NULL);
	pthread_join(tid1, NULL);
}
