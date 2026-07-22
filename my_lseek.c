#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    // 获取文件大小
    off_t size = lseek(fd, 0, SEEK_END);
    printf("File size: %ld bytes\n", size);
    
    // 回到文件开头
    lseek(fd, 0, SEEK_SET);
    
    // 读取前10字节
    char buf[11];
    int n = read(fd, buf, 10);
    buf[n] = '\0';
    printf("First 10 chars: %s\n", buf);
    
    // 跳到第20字节
    lseek(fd, 20, SEEK_SET);
    n = read(fd, buf, 10);
    buf[n] = '\0';
    printf("Chars at 20-30: %s\n", buf);
    
    close(fd);
    return 0;
}
