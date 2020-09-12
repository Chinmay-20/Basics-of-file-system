#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[])
{
	fflush(stdin);
	if((strcmp(argv[1],"--h")==0) || (strcmp(argv[1],"--H")==0) || (strcmp(argv[1],"--help")==0))
	{
		printf("exe_name string to be printed\n");
		return -1;
	}
	if(argc!=3)
	{
		printf("Invalid arguments\n");
		return -1;
	}
	
	
	
	for(int i=1;i<argc;i++)
	{
		printf("%s\t",argv[i]);
		fflush(stdout);
	}
	printf("\n");
	
}
/*
chinmay@chinmay:~/Desktop/Assignment1$ gcc 3.c -o myexe
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe --h
exe_name string to be printed
chinmay@chinmay:~/Desktop/Assignment1$ ./myexe HELLO WORLD
HELLO	WORLD	
chinmay@chinmay:~/Desktop/Assignment1$ 
*/

//4th question
/*chinmay@chinmay:~/Desktop/Assignment1$ make compile
gcc 3.c -o hello
chinmay@chinmay:~/Desktop/Assignment1$ make run
./hello Hello World
Hello	World	
chinmay@chinmay:~/Desktop/Assignment1$ 
*/
