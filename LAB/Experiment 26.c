
#include <stdio.h>
int main() {
    char filename[50], content[100];
    printf("Enter filename to write to: ");
    scanf("%s", filename);
    printf("Enter a word to write: ");
    scanf("%s", content);
    FILE *fp = fopen(filename, "w");
    if(fp) {
        fprintf(fp, "%s\n", content);
        fclose(fp);
        printf("File written successfully using fopen/fprintf.\n");
    } else {
        printf("Failed to open file.\n");
    }
    return 0;
}
