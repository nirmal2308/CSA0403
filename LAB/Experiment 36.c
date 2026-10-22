
#include <stdio.h>
int main() {
    int f[50], p, i, st, len, j, c, a;
    for(i=0; i<50; i++) f[i]=0;
    printf("Linked Allocation\n");
    do {
        printf("Enter starting block and length: ");
        scanf("%d%d", &st, &len);
        for(j=st; j<(st+len); j++) {
            if(f[j]==0) { f[j]=1; printf("Block %d allocated\n", j); }
            else { printf("Block %d already allocated\n", j); len++; }
        }
        printf("Enter 1 to enter more files, 0 to exit: ");
        scanf("%d", &c);
    } while(c==1);
    return 0;
}
