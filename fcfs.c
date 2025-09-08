#include <stdio.h>

int main() {
    int n, i, j;
    int pid[20], at[20], bt[20], ct[20], tat[20], wt[20];
    float total_tat = 0, total_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nP[%d] Arrival Time, Brust Time ", i + 1);
        scanf("%d %d", &at[i],&bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
		at[i]=at[i]+at[j] -(at[j]=at[i]);
		bt[i]=bt[i]+bt[j]-(bt[j]=bt[i]);
		pid[i]=pid[i]+pid[j]-(pid[j]=pid[i]);
            }
        }
    }

    int time = 0;
    for (i = 0; i < n; i++) {
        if (time < at[i])
            time = at[i];

        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];

        time = ct[i];
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time   : %.2f\n", total_wt / n);

    return 0;
}
