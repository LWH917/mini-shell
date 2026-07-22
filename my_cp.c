#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{
	char a[1055];
	int n = 0;
	if(argc<3)
	{
		printf("Usage: %s <src> <tdts>\n ",argv[0]);
		return 1;
	}
	int p=open(argv[1],O_RDONLY);
	int dts = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
	while((n=read(p,a,sizeof(a)))>0)
	{
		write(dts,a,n);
	}
	close(p);
	close(dts);
}
