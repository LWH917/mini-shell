#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf[1];
    int n;
    int lines = 0, words = 0, bytes = 0;
    int in_word = 0;
    
    int fd = (argc > 1) ? open(argv[1], O_RDONLY) : 0;
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    while ((n = read(fd, buf, 1)) > 0) {
        bytes++;
        if (buf[0] == '\n') lines++;
        if (buf[0] == ' ' || buf[0] == '\n' || buf[0] == '\t') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    
    close(fd);
    printf("%d %d %d\n", lines, words, bytes);
    return 0;
}
