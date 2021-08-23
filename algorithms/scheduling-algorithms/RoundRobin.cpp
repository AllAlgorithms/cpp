
// C++ program to implement Round Robin scheduling (RR)
#include<bits/stdc++.h> 
using namespace std; 
  
struct Process 
{ 
   int pid; // Process ID 
   int bt;  // Burst Time 
}; 
  

// Function to find the waiting time for all 
// processes 
void findWaitingTime(Process proc[], int n, int wt[]) 
{ 
    // waiting time for first process is 0 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int i = 1; i < n ; i++ ) 
        wt[i] = proc[i-1].bt + wt[i-1] ; 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(Process proc[], int n, 
                        int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n ; i++) 
        tat[i] = proc[i].bt + wt[i]; 
} 
  
//Function to calculate average time 
void findavgTime(Process proc[], int n) 
{ 
    int wt[n], bt[n] ,tat[n], total_wt = 0, total_tat = 0, quantum=2, current_time=0;
	 // getting the required burst times
	 for(int i=0;i<n;i++)
	 {
	 	bt[i]=proc[i].bt;
	 }
	bool fin=true;
	while(1)
	{
		fin=true;// iterating until process is completed
		for(int i=0;i<n;i++)
		{
			if(bt[i]>0)
			{
				fin=false;
				if(bt[i]>quantum)
				{
					
					bt[i]-=quantum;
					current_time+=quantum;
					
				}
				else
				{
					current_time+=bt[i];
					// process completed
					bt[i]=0;
					wt[i]=current_time-proc[i].bt;
					
				}
			}
		}
		if(fin)
		break;
		
	}
  	
  
    // Function to find turn around time for all processes 
    findTurnAroundTime(proc, n, wt, tat); 
  
    // Display processes along with all details 
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int i = 0; i < n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t " << wt[i] 
             << "\t\t " << tat[i] <<endl; 
    } 
  
    cout << "Average waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
} 
  
// Driver code 
int main() 
{ 
    Process proc[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}}; 
    int n = sizeof proc / sizeof proc[0]; 
  
    findavgTime(proc, n); 
    return 0; 
} 
