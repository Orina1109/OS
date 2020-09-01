#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int* arr, int count)
{
	for (int i = 0; i < count - 1; ++i)
	{
		for(int j = 0; j < count - 1; ++j)
		{
			if (arr[j] > arr[j+1])
				swap(arr + j, arr + j + 1);
		}
	}
	
}

int main()
{
	int arr[10] = {4, 6, 1, 4, 9, 3, 6, 8, 0, 19};
	bubble_sort(arr, 10);
	for (int i = 0; i < 10; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}