#include <stdio.h>
#include <math.h>

void print_triang(int h)
{
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 0; j < i; ++j)
			putc('*', stdout);
		putc('\n', stdout);
	}
}

void print_sq(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			putc('*', stdout);
		putc('\n', stdout);
	}
}

void print_smth(int n)
{
	int peek = 0;
	if (n % 2 == 1)
		peek = n / 2 + 1;
	else 
		peek = n/2;
		
	for (int i = 1; i <= n; ++i)
	{
		if (i < peek)
			for (int k = 0; k < i; ++k)
				putc('*', stdout);
		else if (n % 2 == 0 && (i == peek || i == peek + 1) || i == peek)
			for (int k = 0; k < peek; ++k)
				putc('*', stdout);
		else
			for (int k = 0; k < 2 * peek - i; ++k)
				putc('*', stdout);
		
		putc('\n', stdout);
	}
}


int main(int argc, char** argv)
{
	int n = 0;
	int f = 0;
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &f);
	if (f == 1)
		print_triang(n);
	else if (f == 2)
		print_smth(n);
	else if (f == 3)
		print_sq(n);
	printf("\n");
	
}