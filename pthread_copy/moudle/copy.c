#include<process_copy.h>

/*int main(int argc ,char ** argv)
{
	int block_size = atoi(argv[3]);
	int copy_pos = atoi(argv[4]);
	char buffer[block_size];
	bzero(buffer,sizeof(buffer));
	ssize_t readlen;
 
	int sfd = open(argv[1],O_RDONLY);
	int dfd = open(argv[2],O_RDWR|O_CREAT,0664);

	lseek(sfd,copy_pos,SEEK_SET);
	lseek(dfd,copy_pos,SEEK_SET);
		 
	readlen = read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,readlen);
	close(sfd);
	close(dfd);
			     
	return 0;

}*/




int copy(const char* sfile, const char* dfile, int blocksize, int pos)
{

	//int block_size = atoi(blocksize);
	//int copy_pos = atoi(pos);

	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));
	ssize_t readlen;

	int sfd = open(sfile,O_RDONLY);
	int dfd = open(dfile,O_RDWR|O_CREAT,0664);

	lseek(sfd,pos,SEEK_SET);
	lseek(dfd,pos,SEEK_SET);

	readlen = read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,readlen);

	close(sfd);
	close(dfd);

	return 0;
}


