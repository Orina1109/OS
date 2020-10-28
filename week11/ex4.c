#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main ()
{
	struct stat statbuf;
	int mode = 0x0777;
	int fdin = open ("ex1.txt", O_RDONLY);
	int fdout = open ("ex1.memcpy.txt", O_RDWR | O_CREAT);
	fstat (fdin,&statbuf);
	char* src = mmap (0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 0);
	char* dst = mmap (0, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0);
	memcpy (dst, src, statbuf.st_size);
	return 0;
}