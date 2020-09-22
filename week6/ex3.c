#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int arrive_time;
	int pid;
	int burst_time;
	int executed;
	int last_exec_time;
} process_info;

int is_all_executed(process_info** infos, int count)
{
	for (int i = 0; i < count; ++i)
	{
		if (infos[i]->executed < infos[i]->burst_time)
			return 0;
	}
	return 1;
}

int min(int a, int b)
{
	return a > b ? b : a;
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
		info->last_exec_time = -1;
		infos[i] = info;
	}
	int current_time = 0;
	int total_wait_time = 0;
	int total_burst_time = 0;
	int waiting_time = 0;
	int quantum = 3;
	while (!is_all_executed(infos, count))
	{
	for (int i = 0; i < count; ++i)
	{
		if (infos[i]->executed >= infos[i]->burst_time) continue;
		total_burst_time += min(infos[i]->burst_time - infos[i]->executed, quantum);
		if (infos[i]->arrive_time < current_time)
		{
			//if (infos[i]->last_exec_time != -1)
			//	waiting_time = current_time - infos[i]->last_exec_time;
			//else
			waiting_time = current_time - infos[i]->arrive_time;
			total_wait_time += waiting_time;
			current_time += min(infos[i]->burst_time - infos[i]->executed, quantum);
		}
		else 
		{
			waiting_time = 0;
			current_time += infos[i]->arrive_time - current_time + min(infos[i]->burst_time - infos[i]->executed, quantum);
		}
		printf("Process %d: CT: %d, TAT: %d, WT: %d\n", infos[i]->pid + 1, current_time, min(infos[i]->burst_time - infos[i]->executed, quantum), waiting_time);		
		infos[i]->executed += quantum;
		infos[i]->last_exec_time = current_time;
	}
	}
	printf("--------------------------\n");
	printf("Average WT: %.2f, average TAT: %.2f\n", (double)(total_wait_time)/count, (double)(total_burst_time)/count);
}