
#include <stdio.h>
int main() {
    int n, bt[20], p[20], pr[20], wt[20], tat[20], temp;
    float avg_wt=0, avg_tat=0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        p[i] = i+1;
        printf("P%d BT and Priority: ", i+1);
        scanf("%d %d", &bt[i], &pr[i]);
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(pr[i] > pr[j]) {
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=p[i]; p[i]=p[j]; p[j]=temp;
            }
        }
    }
    wt[0]=0; tat[0]=bt[0]; avg_tat=tat[0];
    for(int i=1; i<n; i++) {
        wt[i] = wt[i-1] + bt[i-1]; tat[i] = wt[i] + bt[i];
        avg_wt += wt[i]; avg_tat += tat[i];
    }
    printf("P\tBT\tPR\tWT\tTAT\n");
    for(int i=0; i<n; i++) printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    printf("Average WT: %.2f\nAverage TAT: %.2f\n", avg_wt/n, avg_tat/n);
    return 0;
}
