#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

int main ()
{
	struct stat statbuf;
	int mode = 0x0777;

	int fdout = open ("ex1.txt", O_RDWR, mode);
	fstat (fdout, &statbuf);

	char* src = "This is a nice day";
	char* dst = mmap (0, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0);
	memset(dst, 0, statbuf.st_size);
	memcpy (dst, src, strlen(src) + 1);
	return 0;
}