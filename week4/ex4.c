#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	char* command = (char*)malloc(1);
	command[0] = '\0';
	for (int i = 1; i < argc; ++i)
	{
		strcat(command, argv[i]);
		strcat(command, " ");
	}
	system(command);
}