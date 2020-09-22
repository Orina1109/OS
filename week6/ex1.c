#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int arrive_time;
	int burst_time;
} process_info;

int main()
{
	int count;
	printf("Enter the count of processes: ");
	scanf("%d", &count);
	process_info** infos = (process_info**)malloc(sizeof(process_info) * count);
	for (int i = 0; i < count; ++i)
	{
		printf("Enter the arrival time and burst time of the process %d: ", i + 1);
		process_info* info = (process_info*)malloc(sizeof(process_info));
		scanf("%d %d", &(info->arrive_time), &(info->burst_time));
		infos[i] = info;
	}
	int current_time = 0;
	int total_wait_time = 0;
	int total_burst_time = 0;
	int waiting_time = 0;
	for (int i = 0; i < count; ++i)
	{
		total_burst_time += infos[i]->burst_time;
		if (infos[i]->arrive_time < current_time)
		{
			waiting_time = current_time - infos[i]->arrive_time;
			total_wait_time += waiting_time;
			current_time += infos[i]->burst_time;
		}
		else 
		{
			waiting_time = 0;
			current_time += infos[i]->arrive_time - current_time + infos[i]->burst_time;
		}
			
		printf("Process %d: CT: %d, TAT: %d, WT: %d\n", i + 1, current_time, infos[i]->burst_time, waiting_time);		
	}
	printf("--------------------------\n");
	printf("Average WT: %.2f, average TAT: %.2f\n", (double)(total_wait_time)/count, (double)(total_burst_time)/count);
}