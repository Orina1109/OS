#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add(int** arr, int* count, int value) 
{
	*arr = realloc(*arr, (*count + 1)*sizeof(int));
	(*arr)[*count] = value;
	(*count)++;
}

int all_finished(int* finished, int count)
{
	for (int i = 0; i < count; ++i)
	{
		if (!finished[i]) return 0;
	}
	return 1;
}

int find_not_finished(int* finished, int count_proc, int* W, int** R, int count_res)
{
	for (int i = 0; i < count_proc; ++i)
	{
		if (!finished[i])
		{
			for (int j = 0; j < count_res; ++j)
			{
				if (R[i][j] > W[j]) continue;
			}
			return i;
		}
	}
	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char buffer[1000];
	fgets(buffer, 1000, stdin);
	char sstream[2000];
	sprintf(sstream, "%s", buffer);
	int countE = 0;
	int* E = malloc(0);
	int value = -1;
	while (sscanf(sstream, "%d", &value) != EOF) 
		add(&E, &countE, value);
	
	fgets(buffer, 1000, stdin);
	fgets(buffer, 1000, stdin);
	sprintf(sstream, "%s", buffer);
	int* A = malloc(0);
	int countA = 0;
	while (sscanf(sstream, "%d", &value) != EOF)
		add(&A, &countA, value);
	
	int** C = malloc(0);
	int count_streams = 0;
	int** R = malloc(0);
	while (1)
	{
		fgets(buffer, 1000, stdin);
		if (strcmp(buffer, "\n") == 0) break;
		sprintf(sstream, "%s", buffer);
		C = realloc(C, sizeof(int*)*(count_streams));
		int count = 0;
		for (int i = 0; i < countA; ++i)
		{
			sscanf(sstream, "%d", &value);
			add(C + count_streams, &count, value);
		}
		count_streams++;
	}
	
	for (int i = 0; i < count_streams; ++i)
	{
		int count = 0;
		int value = 0;
		R = realloc(R, sizeof(int*)*(i+1));
		for (int j = 0; j < countA;)
		{
			scanf("%d", &value);
			add(R + i, &j, value);			
		}
	}
	
	int* W = malloc(sizeof(int)*countA);
	memcpy(W, A, sizeof(int)*countA);
	int* finished = malloc(sizeof(int)*count_streams);
	memset(finished, 0, sizeof(int)*count_streams);
	
	for (int i = 0; i < count_streams; ++i)
	{
		int proc = find_not_finished(finished, count_streams, W, R, countA);
		if (proc == -1) 
		{
			printf("%d processes deadlocked", count_streams - i);
			return 0;
		}
		finished[i] = 1;
		for (int j = 0; j < countA; ++j)
			W[j] += C[i][j];
	}
	printf("no deadlocks detected");
}