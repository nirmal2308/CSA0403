
#include <stdio.h>
#include <sys/stat.h>
int main() {
    char filename[50];
    int mode;
    printf("Enter filename to change permission: ");
    scanf("%s", filename);
    printf("Enter mode (e.g. 0777) in octal format: ");
    scanf("%o", &mode);
    if(chmod(filename, mode) == 0) {
        printf("Permissions changed successfully.\n");
    } else {
        printf("Error changing permissions.\n");
    }
    return 0;
}
