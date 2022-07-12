#include<pthread_copy.h>

typedef struct Info
{
	 const char* sfile;
	 const char* dfile;
	 int blocksize;
	 int pronum;
}Info;

void *jobs(void *arg)
{
	Info* info = (Info*)arg;
	copy(info->sfile,info->dfile,info->blocksize,info->pronum);
	return NULL;
}


int pthread_create1(const char* sfile,const char* dfile, int blocksize, int pronum)
{
	Info info2;

	//pthread_detach(pthread_self());
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	pthread_t tid;
	int flag;
	int err;
	for(flag = 0;flag<pronum;flag++){
		int flag2;
		flag2=flag*blocksize;
		info2.sfile=sfile;
		info2.dfile=dfile;
		info2.blocksize=blocksize;
		info2.pronum=flag2;
		if((err = pthread_create(&tid,NULL,jobs,(void*)&info2))>0){
			printf("thread create fail%s\n",strerror(err));
			exit(0);
		}
		sleep(1);
	}
	pthread_attr_destroy(&attr);
	
	return 0;
}

