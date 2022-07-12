#include <pthread_copy.h>

int file_block(const char* sfile, int pronum)
{
	int fd = open(sfile,O_RDONLY);
	int fsize = lseek(fd,0 ,SEEK_END);

	if(fsize % pronum == 0)
			return fsize/pronum;
	else
			return fsize/pronum + 1;

}
