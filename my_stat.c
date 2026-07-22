#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    struct stat st;
    if (stat(argv[1], &st) < 0) {
        perror("stat");
        return 1;
    }
    
    printf("File: %s\n", argv[1]);
    printf("Size: %ld bytes\n", st.st_size);
    printf("Permissions: %o\n", st.st_mode & 0777);
    printf("Links: %ld\n", st.st_nlink);
    
    return 0;
}
