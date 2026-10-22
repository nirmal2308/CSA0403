
#include <stdio.h>
#include <stdlib.h>
int main() {
    int req[100], i, j, n, head, total=0, size, temp;
    printf("Enter number of requests: "); scanf("%d", &n);
    printf("Enter request sequence:\n");
    for(i=0; i<n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: "); scanf("%d", &head);
    printf("Enter total disk size: "); scanf("%d", &size);
    for(i=0; i<n; i++) for(j=0; j<n-i-1; j++) if(req[j]>req[j+1]) { temp=req[j]; req[j]=req[j+1]; req[j+1]=temp; }
    int index;
    for(i=0; i<n; i++) if(head < req[i]) { index=i; break; }
    for(i=index; i<n; i++) { total += abs(req[i] - head); head = req[i]; }
    total += abs((size-1) - head); head = 0; total += (size-1);
    for(i=0; i<index; i++) { total += abs(req[i] - head); head = req[i]; }
    printf("Total head movement (C-SCAN) = %d\n", total);
    return 0;
}
