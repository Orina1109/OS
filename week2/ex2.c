#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[1024];
	scanf("%s", buffer);
	int len = strlen(buffer);
	for (int i = len - 1; i >= 0; --i)
		putc(buffer[i], stdout);
	printf("\n");
}