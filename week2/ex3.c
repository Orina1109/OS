#include <stdio.h>

int main(int argc, char** argv)
{
	int n = 0;
	sscanf(argv[1], "%d", &n);
	for (int i = 1, h = 1; i <= 2*n - 1; i += 2, ++h)
	{
		int spc_count = n - h;
		for (int j = 0; j < spc_count; ++j)
			putc(' ', stdout);
		for (int j = 0; j < i; ++j)
			putc('*', stdout);
		for (int j = 0; j < spc_count; ++j)
			putc(' ', stdout);
		putc('\n', stdout);
	}
	printf("\n");
	
}