#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(int argc,char* argv[])
{
	int fd=0,numwrite=0;
	if((strcmp(argv[1],"--h")==0) || (strcmp(argv[1],"--H")==0) || (strcmp(argv[1],"--help")==0))
	{
		printf("exe_name filename_to_open the_string_to_write_in_file\n");
		return -1;
	}
		
	if(argc!=3)
	{
		printf("Invalid arguments\n");
		return -1;
	}
	
	fd=open(argv[1],O_WRONLY|O_APPEND);
	if(fd==-1)
	{
		perror("open");
	}
	else
	{
		printf("the file is opened with fd %d\n",fd);
	}
	
	numwrite=write(fd,argv[2],strlen(argv[2]));
	if(numwrite==-1)
	{
		perror("write");
	}
	else
	{
		printf("the number of bytes written are %d\n",numwrite);
	}
	
	
	if(close(fd)==-1)
	{
		perror("close");
	}
	
}
/*
hinmay@chinmay:~/Desktop/Assignment1$ gcc 9.c -o myexe
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe --h
exe_name filename_to_open the_string_to_write_in_file
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe /home/chinmay/Desktop/Assignment1/assignment.txt /home/chinmay/Desktop/Assignment
the file is opened with fd 3
the number of bytes written are 32
chinmay@chinmay:~/Desktop/Assignment1$ 
*/
