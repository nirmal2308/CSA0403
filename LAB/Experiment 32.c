
#include <stdio.h>
int main() {
    int f, p, pages[50], frame[10], time[10], count=0, flag1, flag2, i, j, pos, min;
    printf("Enter number of frames: "); scanf("%d", &f);
    printf("Enter number of pages: "); scanf("%d", &p);
    printf("Enter reference string:\n");
    for(i=0; i<p; ++i) scanf("%d", &pages[i]);
    for(i=0; i<f; ++i) frame[i] = -1;
    for(i=0; i<p; ++i) {
        flag1 = flag2 = 0;
        for(j=0; j<f; ++j) {
            if(frame[j] == pages[i]) {
                time[j] = i; flag1 = flag2 = 1;
                break;
            }
        }
        if(flag1 == 0) {
            for(j=0; j<f; ++j) {
                if(frame[j] == -1) {
                    count++; frame[j] = pages[i]; time[j] = i; flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0) {
            min = time[0]; pos = 0;
            for(j=1; j<f; ++j) { if(time[j] < min) { min = time[j]; pos = j; } }
            count++; frame[pos] = pages[i]; time[pos] = i;
        }
    }
    printf("\nTotal Page Faults = %d\n", count);
    return 0;
}
