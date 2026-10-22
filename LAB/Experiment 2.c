
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    char src[50], dest[50], c;
    printf("Enter source filename: ");
    scanf("%s", src);
    printf("Enter destination filename: ");
    scanf("%s", dest);
    int fd1 = open(src, O_RDONLY);
    if(fd1 < 0) { printf("Cannot open source file\n"); exit(1); }
    int fd2 = open(dest, O_CREAT | O_WRONLY, 0666);
    while(read(fd1, &c, 1) > 0) write(fd2, &c, 1);
    printf("File copied successfully.\n");
    close(fd1); close(fd2);
    return 0;
}
