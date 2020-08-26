#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("sizeof int a = %ld, value = %d;\nsizeof float b = %ld, value = %f;\nsizeof double c = %ld, value = %lf\n", sizeof(int), a, sizeof(float), b, sizeof(double), c);
}
