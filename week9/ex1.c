#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int frame_id;
	int age;
} PT_Node;

PT_Node** find_or_oldest(PT_Node** page_table, int count, int target_frame)
{
	PT_Node** oldest = NULL;
	for (int i = 0; i < count; ++i)
	{
		if (page_table[i] == NULL) return &page_table[i];
		if (page_table[i]->frame_id == target_frame) return &page_table[i];
		if (oldest == NULL) oldest = &page_table[i];
		else if ((*oldest)->age < page_table[i]->age) oldest = &page_table[i];
	}
	return oldest;
}

void age_up(PT_Node** page_table, int count)
{
	for (int i = 0; i < count && page_table[i] != NULL; ++i)
		page_table[i]->age++;

}

int main(int argc, char** argv)
{
	freopen("Lab 09 input.txt", "r", stdin);
	int count = strtol(argv[1], NULL, 10);
		
	PT_Node** page_table = (PT_Node**)malloc(sizeof(PT_Node*) * count);
	memset(page_table, 0, sizeof(PT_Node*) * count);
	int tmp_frame;
	int hits = 0;
	int miss = 0;
	int p_count = 0;
	while (scanf("%d", &tmp_frame) != EOF)
	{
		p_count++;
		age_up(page_table, count);
		PT_Node** node = find_or_oldest(page_table, count, tmp_frame);
		if (*node == NULL)
		{
			*node = (PT_Node*)malloc(sizeof(PT_Node));
			(*node)->frame_id = tmp_frame;
			(*node)->age = 0;
			miss++;
		}
		else if ((*node)->frame_id == tmp_frame)
		{
			hits++;
			(*node)->age = 0;
		}
		else
		{
			(*node)->frame_id = tmp_frame;
			(*node)->age = 0;
			miss++;
		}
	}
	printf("Hitrate: %lf, missrate: %lf\n", (double)hits / (double)p_count, (double)miss / (double)p_count);
}