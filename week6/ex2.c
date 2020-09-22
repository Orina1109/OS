#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int arrive_time;
	int pid;
	int burst_time;
	int executed;
} process_info;

process_info* find_min_job(process_info** infos, int count, int current_time)
{
	process_info* min_job_info = NULL;
	for (int i = 0; i < count; ++i)
	{
		if (infos[i]->executed) continue;
		if (infos[i]->arrive_time <= current_time)
		{
			if (min_job_info == NULL)
				min_job_info = infos[i];
			else if (infos[i]->burst_time < min_job_info->burst_time)
				min_job_info = infos[i];
		}
	}
	return min_job_info;
}

int main()
{
	int count;
	printf("Enter the count of processes: ");
	scanf("%d", &count);
	process_info** infos = (process_info**)malloc(sizeof(process_info*) * count);
	for (int i = 0; i < count; ++i)
	{
		printf("Enter the arrival time and burst time of the process %d: ", i + 1);
		process_info* info = (process_info*)malloc(sizeof(process_info));
		scanf("%d %d", &(info->arrive_time), &(info->burst_time));
		info->executed = 0;
		info->pid = i;
		infos[i] = info;
	}
	int current_time = 0;
	int total_wait_time = 0;
	int total_burst_time = 0;
	int waiting_time = 0;
	for (int i = 0; i < count; ++i)
	{
		process_info* info;
		
		do 
		{
			info = find_min_job(infos, count, current_time);
			if (info == NULL)
				current_time++;
		} while (info == NULL);
		
		total_burst_time += info->burst_time;
		waiting_time = current_time - info->arrive_time;
		total_wait_time += waiting_time;
		current_time += info->burst_time;
		info->executed = 1;
		printf("Process %d: CT: %d, TAT: %d, WT: %d\n", info->pid + 1, current_time, infos[i]->burst_time, waiting_time);		
	}
	printf("--------------------------\n");
	printf("Average WT: %.2f, average TAT: %.2f\n", (double)(total_wait_time)/count, (double)(total_burst_time)/count);
}