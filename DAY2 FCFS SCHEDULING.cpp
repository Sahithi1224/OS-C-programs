#include <stdio.h>

int main()
{
    int n = 3;
    int arrival_time[n], burst_time[n], completion_time[n], waiting_time[n], turnaround_time[n];
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    // initialize arrival time and burst time
    for (int i = 0; i < n; i++) {
        arrival_time[i] = 0;
    }
    burst_time[0] = 2;
    burst_time[1] = 4;
    burst_time[2] = 8;

    // calculate completion time for each process
    completion_time[0] = burst_time[0];
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i-1] + burst_time[i];
    }

    // calculate waiting time for each process
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = completion_time[i-1] - arrival_time[i];
    }

    // calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
    }

    // calculate average waiting time and average turnaround time
    for (int i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // print results
    printf("Process\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, burst_time[i], arrival_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
