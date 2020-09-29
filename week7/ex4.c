#include <stdio.h>
#include <stdlib.h>

void* realloc_new(void* ptr, size_t new_size)
{
	if (ptr == NULL)
		return malloc(new_size);
	if (new_size == 0)
	{
		free(ptr);
		return ptr;
	}
	return realloc(ptr, new_size);
}

int main()
{
	
}