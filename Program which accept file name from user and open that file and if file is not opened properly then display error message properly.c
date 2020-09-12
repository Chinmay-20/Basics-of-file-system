#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<errno.h>

int main(int argc,char* argv[])
{
	int fd=0;
	
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
		printf("The errno is %d\n",errno);
	}
	else
	{
		printf("the file is opened with fd %d\n",fd);
	}
	
	if(close(fd)==-1)
	{
		perror("close");
		printf("The errno is %d\n",errno);
	}
	
}
/*
chinmay@chinmay:~/Desktop/Assignment1$ gcc 6.c -o myexe
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe
Invalid arguments
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe --H
exe_name filename_to_open
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe /home/chinmay/Desktop/Assignment1/assignmnt.txt 
open: No such file or directory
The errno is 2
close: Bad file descriptor
The errno is 9
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe /home/chinmay/Desktop/Assignment1/assignment.txt 
the file is opened with fd 3
chinmay@chinmay:~/Desktop/Assignment1$ 
*/
