
#include <stdio.h>
int main() {
    int n, bt[20], at[20], pr[20], rt[20], remain=0, time, smallest;
    int sum_wait=0, sum_turnaround=0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("P%d AT, BT, and Priority: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }
    pr[19] = 9999;
    for(time=0; remain!=n; time++) {
        smallest = 19;
        for(int i=0; i<n; i++) {
            if(at[i] <= time && pr[i] < pr[smallest] && rt[i] > 0) smallest = i;
        }
        rt[smallest]--;
        if(rt[smallest] == 0) {
            remain++;
            int endTime = time + 1;
            int tat = endTime - at[smallest];
            int wt = tat - bt[smallest];
            sum_wait += wt; sum_turnaround += tat;
        }
    }
    printf("\nAverage WT: %.2f\nAverage TAT: %.2f\n", sum_wait*1.0/n, sum_turnaround*1.0/n);
    return 0;
}
