
#include <stdio.h>
int main() {
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10];
    printf("Enter number of blocks: "); scanf("%d", &bno);
    printf("Enter size of each block:\n");
    for(int i=0; i<bno; i++) { scanf("%d", &bsize[i]); flags[i]=0; }
    printf("Enter number of processes: "); scanf("%d", &pno);
    printf("Enter size of each process:\n");
    for(int i=0; i<pno; i++) { scanf("%d", &psize[i]); allocation[i]=-1; }
    
    for(int i=0; i<pno; i++) {
        int bstIdx = -1;
        for(int j=0; j<bno; j++) {
            if(bsize[j] >= psize[i]) {
                if(bstIdx == -1) bstIdx = j;
                else if(bsize[bstIdx] > bsize[j]) bstIdx = j;
            }
        }
        if(bstIdx != -1) {
            allocation[i] = bstIdx;
            bsize[bstIdx] -= psize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(int i=0; i<pno; i++) {
        printf("%d\t\t%d\t\t", i+1, psize[i]);
        if(allocation[i] != -1) printf("%d\n", allocation[i]+1);
        else printf("Not Allocated\n");
    }
    return 0;
}
