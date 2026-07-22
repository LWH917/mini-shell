#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd[2];          // 管道文件描述符
    pipe(fd);           // 创建管道
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // 子进程：执行 ls，输出到管道
        close(fd[0]);                    // 关闭读端（子进程只写）
        dup2(fd[1], 1);                  // 把标准输出重定向到管道写端
        close(fd[1]);                     // 关闭原写端（已重定向）
        execlp("ls", "ls", NULL);         // 执行 ls，输出到管道
        perror("exec ls");
        return 1;
    }
    else {
        // 父进程：执行 wc -l，从管道读输入
        close(fd[1]);                    // 关闭写端（父进程只读）
        dup2(fd[0], 0);                  // 把标准输入重定向到管道读端
        close(fd[0]);                     // 关闭原读端（已重定向）
        execlp("wc", "wc", "-l", NULL);   // 执行 wc -l，从管道读
        perror("exec wc");
        return 1;
    }
    
    return 0;
}


