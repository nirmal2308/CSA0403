
#include <stdio.h>
#include <dirent.h>
int main() {
    char dirname[50];
    printf("Enter directory to list (e.g. .): ");
    scanf("%s", dirname);
    struct dirent *de;
    DIR *dr = opendir(dirname);
    if (dr == NULL) { printf("Could not open directory\n"); return 0; }
    printf("Files in directory:\n");
    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }
    closedir(dr);
    return 0;
}
