
#include <stdio.h>
#include <sys/stat.h>
int main() {
    char filename[50];
    printf("Enter filename to stat: ");
    scanf("%s", filename);
    struct stat st;
    if(stat(filename, &st) == 0) {
        printf("File size of %s is %ld bytes\n", filename, st.st_size);
    } else {
        printf("File not found or error stating.\n");
    }
    return 0;
}
