#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// 信号处理函数
void handle_sigint(int sig)
{
    printf("\nCaught signal %d (Ctrl+C), but I won't quit!\n", sig);
}

int main()
{
    // 注册信号处理函数：收到 SIGINT 时执行 handle_sigint
    signal(SIGINT, handle_sigint);
    
    printf("Running... Press Ctrl+C to test\n");
    
    while (1) {
        sleep(1);
        printf("Still alive...\n");
    }
    
    return 0;
}
