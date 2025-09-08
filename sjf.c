#include <stdio.h>

int main() {
    int n, i, j, idx;
    int time = 0, completed_count = 0;
    float total_tat = 0, total_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
	int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    int completed[20] = {0};


    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }


    while (completed_count < n) {
        int min_bt = 9999;
        idx = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0) {
                if (bt[i] < min_bt || (bt[i] == min_bt && at[i] < at[idx])) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
        } else {
            ct[idx] = time + bt[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            total_tat += tat[idx];
            total_wt += wt[idx];

            completed[idx] = 1;
            completed_count++;
            time = ct[idx];
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time   : %.2f\n", total_wt / n);

    return 0;
}
