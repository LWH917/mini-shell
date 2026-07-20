#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main()
{
	char cmd [100];
	while(1)
	{
		printf("myshell> ");
		scanf("%s",cmd);
		if(strcmp(cmd,"exit") == 0)
		{
			break;
		}
		pid_t pid = fork();
		if(pid == 0)
		{
			execlp (cmd,cmd,NULL);
			perror("exec");
			return 1;
		}
		else
		{
			wait(NULL);
		}
	}
		printf("Bye!\n");
		return 0;
}

