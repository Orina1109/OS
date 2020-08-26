#include <stdio.h>

void swap(int* a, int* b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
}