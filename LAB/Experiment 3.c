
#include <stdio.h>
int main() {
    int n, bt[20], wt[20], tat[20];
    float avg_wt=0, avg_tat=0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
    for(int i=0; i<n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0; tat[0] = bt[0]; avg_tat = tat[0];
    for(int i=1; i<n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i]; avg_tat += tat[i];
    }
    printf("P\tBT\tWT\tTAT\n");
    for(int i=0; i<n; i++) printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    printf("Average WT: %.2f\nAverage TAT: %.2f\n", avg_wt/n, avg_tat/n);
    return 0;
}
