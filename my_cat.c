#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{
	char a[1055];
	int  n =  0;
	if(argc < 2)
	{
		printf("Usage: %s <filename>\n",argv[0]);
		return 1;
	}
	int p=open(argv[1],O_RDONLY);
	if(p < 0)
	{
		perror("open");
		return 1;
	}
	while((n = read(p,a,sizeof(a)))>0)
	{
		write(1,a,n);
	}
}
