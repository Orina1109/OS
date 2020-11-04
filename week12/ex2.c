#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int* argc, char** argv)
{
	char buffer[2048];
	if (*argc > 2 && strcmp(argv[1], "-a") == 0)
	{
		while (scanf("%s", buffer) != NULL)
		{
			gets(buffer);
			for (int i = 2; i < *argc; ++i)
			{
				int f = open(argv[i], O_RDWR | O_CREAT);
				int count = strlen(buffer);
				write(f, buffer, count);
				close(f);
			}
			printf("%s", buffer);
		}
	}
}