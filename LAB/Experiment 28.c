
#include <stdio.h>
#include <string.h>
int main() {
    char line[100], pattern[20];
    printf("Enter a string: ");
    scanf(" %[^\n]", line);
    printf("Enter pattern to grep: ");
    scanf("%s", pattern);
    if (strstr(line, pattern)) {
        printf("Match found: %s\n", line);
    } else {
        printf("No match found.\n");
    }
    return 0;
}
