
#include<stdio.h> 
int main() { 
    int n, qt, count=0, temp, sq=0, bt[10], wt[10], tat[10], rem_bt[10]; 
    float awt=0, atat=0; 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
    for(int i=0; i<n; i++) {
        printf("Enter BT for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter quantum: "); 
    scanf("%d", &qt); 
    while(1) {
        int done = 1;
        for(int i=0; i<n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;
                if(rem_bt[i] > qt) { sq += qt; rem_bt[i] -= qt; }
                else { sq = sq + rem_bt[i]; wt[i] = sq - bt[i]; rem_bt[i] = 0; }
            }
        }
        if(done == 1) break;
    }
    for(int i=0; i<n; i++) {
        tat[i] = bt[i] + wt[i];
        awt += wt[i]; atat += tat[i];
    }
    printf("Average WT: %.2f\nAverage TAT: %.2f\n", awt/n, atat/n);
    return 0; 
}
