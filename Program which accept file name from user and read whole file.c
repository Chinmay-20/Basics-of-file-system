#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(int argc,char* argv[])
{
	int fd=0,numread=0;
	char buf[10];
	if(argc!=2)
	{
		printf("Invalid arguments\n");
		return -1;
	}
	if((strcmp(argv[1],"--h")==0) || (strcmp(argv[1],"--H")==0) || (strcmp(argv[1],"--help")==0))
	{
		printf("exe_name filename_to_open\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		perror("open");
	}
	else
	{
		printf("the file is opened with fd %d\n",fd);
	}
	
	while((numread=read(fd,buf,10))!=0)
	{
		printf("%d\n",numread);
		printf("the number of bytes read are %ld and the data read is %s\n",strlen(buf),buf);
		memset(buf,0,10);
		numread=0;
	}
	if(numread==-1)
	{
		perror("read");
	}
	
	if(close(fd)==-1)
	{
		perror("close");
	}
	
}
/*
chinmay@chinmay:~/Desktop/Assignment1$ gcc 8.c -o myexe
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe /home/chinmay/Desktop/Assignment1/assignment.txt 
the file is opened with fd 3
10
the number of bytes read are 10 and the data read is qwertyuiop
10
the number of bytes read are 10 and the data read is asdfghjklz
7
the number of bytes read are 7 and the data read is xcvbnm

chinmay@chinmay:~/Desktop/Assignment1$ 
*/
