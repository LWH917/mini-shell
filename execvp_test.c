#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    
    if (pid == 0) {
        // 子进程：执行 ls -l
        char *argv[] = {"pwd",NULL};
        execvp("pwd", argv);
        perror("execvp");
        return 1;
    }
    
    // 父进程：等待子进程结束，获取状态
    int status;
    waitpid(pid, &status, 0);
    
    if (WIFEXITED(status)) {
        printf("Child exited with code %d\n", WEXITSTATUS(status));
    }
    
    return 0;
}
