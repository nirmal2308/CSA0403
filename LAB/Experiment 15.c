
#include <stdio.h>
int main() {
    int num_dirs, num_files;
    char dir[10][20], files[10][10][20];
    printf("Enter number of user directories: ");
    scanf("%d", &num_dirs);
    for(int i=0; i<num_dirs; i++) {
        printf("Enter name of directory %d: ", i+1);
        scanf("%s", dir[i]);
        printf("Enter number of files in %s: ", dir[i]);
        scanf("%d", &num_files);
        for(int j=0; j<num_files; j++) {
            printf("Enter file %d name: ", j+1);
            scanf("%s", files[i][j]);
        }
        files[i][num_files][0] = '\0';
    }
    printf("\nTwo Level Directory Structure:\n");
    for(int i=0; i<num_dirs; i++) {
        printf("Directory %s:\n", dir[i]);
        for(int j=0; files[i][j][0] != '\0'; j++) {
            printf("\t%s\n", files[i][j]);
        }
    }
    return 0;
}
