
#include <stdio.h>
struct Employee { int id; char name[20]; };
int main() {
    FILE *fp = fopen("emp.dat", "wb+");
    int n, search_id;
    printf("Enter number of employees to add: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        struct Employee e;
        printf("Enter ID and Name: ");
        scanf("%d %s", &e.id, e.name);
        fwrite(&e, sizeof(e), 1, fp);
    }
    printf("Enter employee index (0 to %d) to randomly access: ", n-1);
    scanf("%d", &search_id);
    struct Employee e_read;
    fseek(fp, search_id * sizeof(struct Employee), SEEK_SET);
    fread(&e_read, sizeof(e_read), 1, fp);
    printf("Read Employee: ID=%d, Name=%s\n", e_read.id, e_read.name);
    fclose(fp);
    return 0;
}
