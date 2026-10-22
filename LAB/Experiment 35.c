
#include <stdio.h>
int main() {
    int f[50], index[50], i, n, ind, c;
    for(i=0; i<50; i++) f[i]=0;
    do {
        printf("Enter index block: ");
        scanf("%d", &ind);
        if(f[ind] != 1) {
            printf("Enter number of blocks and blocks for the index: ");
            scanf("%d", &n);
            int valid=1;
            for(i=0; i<n; i++) {
                scanf("%d", &index[i]);
                if(f[index[i]] == 1) valid=0;
            }
            if(valid) {
                f[ind] = 1;
                for(i=0; i<n; i++) f[index[i]] = 1;
                printf("Allocated!\n");
            } else printf("Some blocks are already allocated.\n");
        } else printf("Index block already allocated.\n");
        printf("Enter 1 to enter more files, 0 to exit: ");
        scanf("%d", &c);
    } while(c==1);
    return 0;
}
