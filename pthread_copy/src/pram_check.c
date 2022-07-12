#include<pthread_copy.h>


int pram_check(int argc,const char* sfile, int pronum)
{
	if(argc < 3){
		printf("ERROR:canshu queshao!\n");
		exit(0);
	}

	if((access(sfile,F_OK))!=0){
		printf("EEEOR:yuanwenjian bucunzai!\n");
		exit(0);
	}
	if(pronum <=0 || pronum >100){
		printf("ERROE:jincheng not <0 and >100\n");
		exit(0);
	}

	return 0;
}
