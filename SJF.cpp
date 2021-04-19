// C++ program to implement Shortest Job First
// IMP NOTE the Arrival Time of all the processes is same ("ZERO")
#include<iostream>
using namespace std;

class SJF		// SJF -> Sortest Job First
{
	
	int p[20],bt[20],wt[20],tat[20];
	float wtavg, tatavg;
	int i, k, n, temp;
	public:
		
	void readBT()		// function to take burst time
	{
		cout<<"enter the no of processes ----\n";	//taking total number of processes from user
		cin>>n;
		for (i=0;i<n;i++)
		{
			p[i]=i;
			cout<<"\nEnter Burst Time for process "<<i+1<<" ";	//taking burst time from user
			cin>>bt[i];
		}
	}
	
	void sortBT()
	{
		for(i=0;i<n;i++)		//sorting burst time in ascending order through selection sort method
			for(k=i+1;k<n;k++)
			if(bt[i]>bt[k])
			{
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
			}
	}
	
	void calAverageTime() //function for calculating average waiting time and Turn Around Time
	{
		wt[0]=wtavg=0;
		tat[0]=tatavg=bt[0];
		
		for(i=1;i<n;i++)
		{
			wt[i]=wt[i-1]+bt[i-1];
			tat[i]=tat[i-1]+bt[i];
			wtavg=wtavg+wt[i];
			tatavg=tatavg+tat[i];
		}
		wtavg=wtavg/n;
		tatavg=tatavg/n;	
		
	}
	
	void display()
	{	//displaying data
		cout<<"\n\n*****************************************************************";
		cout<<"\n\nprocesses "<<"Burst time "<<" waiting time "<<" turn around time"<<"\n";	
			
		for(int i=0;i<n;i++)
		{
			cout<<" "<<i+1<<"\t\t"<<bt[i]<<"\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n\n";
				
		}
		cout<<"******************************************************************\n\n";
		
		cout<<"average waiting time "<<wtavg<<" ms \n";
		cout<<"average turn around time "<<tatavg<<" ms\n\n";
		}	
};	// end of the class


int main()
{
	SJF o1;
	o1.readBT();
	o1.sortBT();
	o1.calAverageTime();
	o1.display();
}
