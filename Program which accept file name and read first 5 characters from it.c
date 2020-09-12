#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(int argc,char* argv[])
{
	int fd=0,numread=0;
	char buf[5];
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
	
	
	numread=read(fd,buf,5);
	if(numread==-1)
	{
		perror("read");
	}
	else if(numread==5)
	{
		printf("the number of bytes read are %d\n",numread);
		printf("the data is %s\n",buf);
	}
	
	if(close(fd)==-1)
	{
		perror("close");
	}
	
}
/*
chinmay@chinmay:~/Desktop/Assignment1$ gcc 7.c -o myexe
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe
Invalid arguments
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe --h
exe_name filename_to_open
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe /home/chinmay/Desktop/Assignment1/assignment.txt 
the file is opened with fd 3
the number of bytes read are 5
the data is qwert
chinmay@chinmay:~/Desktop/Assignment1$ 
*/
