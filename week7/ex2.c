#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter N: ");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
}