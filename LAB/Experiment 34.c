
#include <stdio.h>
int main() {
    int f[50], i, st, len, j, c, k;
    for(i=0; i<50; i++) f[i]=0;
    printf("Sequential File Allocation\n");
    do {
        printf("Enter starting block and length of file: ");
        scanf("%d%d", &st, &len);
        for(j=st; j<(st+len); j++) {
            if(f[j] == 0) f[j] = 1;
            else break;
        }
        if(j == (st+len)) printf("File allocated sequentially.\n");
        else printf("Block already allocated.\n");
        printf("Enter 1 to enter more files, 0 to exit: ");
        scanf("%d", &c);
    } while(c==1);
    return 0;
}
