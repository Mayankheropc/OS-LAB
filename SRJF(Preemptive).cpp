// C++ program to implement Shortest Remaining Time First
// Shortest Remaining Job First (SRJF)
// this algorithm is Preemptive

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct proccess
{
	float at,bt,ct,ta,wt,btt;
	string pro_id;
	
	/*
		at = Arrival time,
		bt = Burst time,
		ct = Completion time,
		ta = Turn around time,
		wt = Waiting time
	*/
                                                 
}Schedule; 

bool compare(Schedule a,Schedule b)
{
	return a.at<b.at;

	/* This Schedule will always return TRUE
	if above condition comes*/
}
bool compare2(Schedule a,Schedule b)
{
	return a.bt<b.bt;

	/* This Schedule will always return TRUE
	if above condition comes*/
}

int main()
{
	Schedule pro[10];
	//An array of Processes
	int n, i, j, pcom;
	//n = number of processes, i= iteration variable

	cout<<"Enter the number of Process = ";
	cin>>n;

	cout<<"\nIMP. NOTE process ID should be a number";

	for(i=0;i<n;i++)
	{
		cout<<"\nfor PROCESS "<<i+1;
		cout<<"\nenter process ID = ";
		cin>>pro[i].pro_id;
		cout<<"enter arrival time = ";
		cin>>pro[i].at;
		cout<<"enter burst time = ";
		cin>>pro[i].bt;
		pro[i].btt=pro[i].bt;
	}

	sort(pro,pro+n,compare);

	/*sort is a predefined funcion  defined in algorithm.h header file,
	it will sort the processes according to their arrival time*/

	i=0;
	pcom=0; // pcom = process complete
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].at>i)
			break;
		}

		sort(pro,pro+j,compare2);

		/*sort is a predefined funcion  defined in algorithm.h header file,
	it will sort the processes according to their burst time*/

		if(j>0)
		{

			for(j=0;j<n;j++)
			{
				if(pro[j].bt!=0)
				break;
			}
			if(pro[j].at>i)

			{
				i=pro[j].at;

			}
			pro[j].ct=i+1;
			pro[j].bt--;
		}
		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].bt==0)
			pcom++;
		}
	}

	cout<<"\nProcess ID\tArrival time\tBurst time\tComplition time  \tTurn around time\tWating time\n";

	float total_wt=0,total_tat=0;

	for(i=0;i<n;i++)
	{
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].btt;

		total_wt = total_wt + pro[i].wt;
		total_tat = total_tat + pro[i].ta;
		
		/*Printing the Process id, arrival time, burst time,
		completion time, turn around time, waiting time*/

		
		cout<<pro[i].pro_id<<"\t \t"<<pro[i].at<<"\t \t"<<pro[i].btt<<"\t \t"<<pro[i].ct<<"\t \t \t"<<pro[i].ta<<"\t \t \t"<<pro[i].wt;
		cout<<endl;
	}	
	
	
	cout << "\nAVERAGE WAITING TIME = "
		<< (float)total_wt / (float)n;
	cout << "\nAVERAGE TURN AROUND TIME = "
		<< (float)total_tat / (float)n;
	cout<<endl;
	
	return 0;
}
