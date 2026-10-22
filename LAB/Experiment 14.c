
#include <stdio.h>
int main() {
    int n; char dir[10], files[10][20];
    printf("Enter directory name: ");
    scanf("%s", dir);
    printf("Enter number of files to create: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("Enter name of file %d: ", i+1);
        scanf("%s", files[i]);
    }
    printf("\nDirectory: %s\nFiles:\n", dir);
    for(int i=0; i<n; i++) printf("\t%s\n", files[i]);
    return 0;
}
