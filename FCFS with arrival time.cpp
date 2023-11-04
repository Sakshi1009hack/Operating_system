#include<iostream>
#include<vector>

using namespace std;

struct Process {
    int id;          // Process ID
    int arrivalTime; // Arrival time
    int burstTime;   // Burst time
};

int main() {
    int n; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input the details of each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }

    // Sort the processes based on arrival time (if not already sorted)
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0; // Current time
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for (const Process& p : processes) {
        // Calculate waiting time
        int waitingTime = max(0, currentTime - p.arrivalTime);
        // Calculate turnaround time
        int turnaroundTime = waitingTime + p.burstTime;

        totalWaitingTime += waitingTime;
        totalTurnaroundTime += turnaroundTime;

        // Update the current time
        currentTime = max(currentTime, p.arrivalTime) + p.burstTime;

        // Print the details for the process
        cout << "P" << p.id << "\t" << p.arrivalTime << "\t\t" << p.burstTime << "\t\t"
             << waitingTime << "\t\t" << turnaroundTime << endl;
    }

    double averageWaitingTime = totalWaitingTime / n;
    double averageTurnaroundTime = totalTurnaroundTime / n;

    cout << "\nAverage Waiting Time: " << averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;

    return 0;
}

