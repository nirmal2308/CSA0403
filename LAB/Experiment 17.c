
#include <stdio.h>
int main() {
    int n, m, i, j, k;
    printf("Enter number of processes: "); scanf("%d", &n);
    printf("Enter number of resources: "); scanf("%d", &m);
    int alloc[20][20], max[20][20], avail[20];
    printf("Enter Allocation Matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &alloc[i][j]);
    printf("Enter Max Matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &max[i][j]);
    printf("Enter Available Resources:\n");
    for(i=0; i<m; i++) scanf("%d", &avail[i]);
    int f[20], ans[20], ind=0, need[20][20];
    for(i=0; i<n; i++) { f[i]=0; for(j=0; j<m; j++) need[i][j] = max[i][j] - alloc[i][j]; }
    for(k=0; k<5; k++) {
        for(i=0; i<n; i++) {
            if(f[i] == 0) {
                int flag = 0;
                for(j=0; j<m; j++) if(need[i][j] > avail[j]) { flag = 1; break; }
                if(flag == 0) {
                    ans[ind++] = i;
                    for(j=0; j<m; j++) avail[j] += alloc[i][j];
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for(i=0; i<n; i++) if(f[i] == 0) { flag = 0; printf("System is not safe\n"); break; }
    if(flag == 1) {
        printf("Safe Sequence is: ");
        for(i=0; i<n-1; i++) printf(" P%d ->", ans[i]);
        printf(" P%d\n", ans[n-1]);
    }
    return 0;
}
