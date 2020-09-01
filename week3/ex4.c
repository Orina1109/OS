#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void q_sort(int* arr, int count)
{
	if (count <= 1)
		return;
	int pivot = rand() % count;
	int count_less = 0;
	for (int i = 0; i < count; ++i)
	{
		if (arr[i] < arr[pivot])
			count_less++;
	}
	swap(arr + pivot, arr + count_less);
	pivot = count_less;
	int high = pivot + 1;
	int low = 0;
	for (int i = 0; i < count; ++i)
	{
		if (i == pivot)
			continue;
		if (arr[i] > arr[pivot] && i < pivot)
		{
			swap(arr + i, arr + high);
			high++;
		}
		else if (arr[i] < arr[pivot] && i > pivot)
		{
			swap(arr + i, arr + low);
			low++;
		}
	}
	q_sort(arr, pivot);
	q_sort(arr + pivot + 1, count - pivot - 1);
}

int main()
{
	int arr[15] = {3, 6, 3, 8, 1, 5, 0, 14, 7, 25, 6, -9, 5, -8, 0};
	q_sort(arr, 15);
	for (int i = 0; i < 15; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
