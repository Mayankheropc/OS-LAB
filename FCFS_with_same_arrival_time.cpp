// C++ program for implementation of FCFS scheduling
// IMP NOTE THIS PROGRAM ASSUME THE ARIVAL TIME OF ALL THE PROCESSES = "ZERO"
#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[])	//  Function to find the waiting time for all processes
{
	wt[0] = 0;		// waiting time for first process is 0
	
	for(int i=1; i<n; i++)		// calculating waiting time
		wt[i]= bt[i-1]+wt[i-1];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])		// Function to calculate turn around time
{
	for (int  i = 0; i < n ; i++)	// calculating TAT
    	tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	
	findWaitingTime(processes, n, bt, wt);	// to find the waiting time of all the processes
	
	findTurnAroundTime(processes, n, bt, wt, tat);		// to find the TAT of all the processes
	
	cout <<"Processes   Burst time   Waiting time   Turn around time\n";
	
	for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout<<"   "<<i+1<< "\t\t" <<bt[i]<<"\t    "<< wt[i] <<"\t\t  " <<tat[i]<<endl;
    }
    
    cout<< "Average waiting time = "<<(float)total_wt/(float)n;			// print avg WT 
    
    cout<< "\nAverage turn around time = "<<(float)total_tat/(float)n;	// print avg TAT

}

int main()
{
    int processes[] = { 1, 2, 3, 4};		//process id's
    int n = sizeof processes / sizeof processes[0];
  
    int  burst_time[] = {7, 3, 8, 2};		//Burst time of all processes
  
    findavgTime(processes,n,burst_time);
    return 0;
}
