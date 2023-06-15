#include<stdio.h>
#include<conio.h>


void waitingTime(int proc[], int n, int burst_time[], int wait_time[]){
    int i;
    wait_time[0] = 0;

    for(i=1; i<n; i++){
        wait_time[i] = burst_time[i-1] + wait_time[i-1];
    }
}

int turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[]){
    int i;
    for(i=0; i<n; i++){
        tat[i] = burst_time[i] + wait_time[i];
    }
}

void avgtime(int proc[], int n, int burst_time[]){
    int wait_time[n], tat[n];
    int total_wt = 0, total_tat = 0, i;
    waitingTime(proc, n, burst_time, wait_time);
    turnaroundtime(proc, n, burst_time, wait_time, tat);
    printf("Process\tBurst Time\tWait Time\tTurnaround Time\n");
    for(i=0; i<n; i++){
        total_wt = total_wt + wait_time[i];
        total_tat = total_tat + tat[i];
        printf("%d  \t%d  \t\t%d \t\t\t%d\n",i+1, burst_time[i], wait_time[i], burst_time[i]+wait_time[i]);
        printf("\n");
    }

    printf("Average waiting time: %d", total_wt/n);
    printf("\n");
    printf("Average turn around time: %d", total_tat/n);
}

int main(){
    int proc[10];
    int n = 10, i;
    int burst_time[10];
    for(i=0; i<n; i++){
        proc[i] = i+1;
    }
    for(i=0; i<10; i++){
        printf("Enter val %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }
    avgtime(proc, n, burst_time);
    return -1;
}
