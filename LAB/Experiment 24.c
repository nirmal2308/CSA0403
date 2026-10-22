
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    char filename[50];
    printf("Enter filename to create: ");
    scanf("%s", filename);
    int fd = creat(filename, 0644);
    if(fd >= 0) printf("File '%s' created successfully with fd = %d\n", filename, fd);
    else printf("Error creating file\n");
    close(fd);
    return 0;
}
