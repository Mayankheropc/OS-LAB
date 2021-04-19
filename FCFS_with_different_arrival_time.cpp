//IMP NOTE The arrival time of the processes should be given in ascending order!
#include<iostream>
using namespace std;

class FCFS        // First Come First Serve
{
	int n, i, j, p[10], temp;
	int AT[10], BT[10], WT[10], TAT[10], x[10];		   // AT = arrival time, BT = burst time, WT = wating time, TAT = turn around time 
	float AWT=0, ATAT=0;                                            // AWT = average Wating time,  ATAT = average turn around time
	
  public: 
  
    void getdata()
    {
    	cout<<"\n Enter total number of process(less than 10): ";
    	cin>>n;
    	for(i=0; i<n; i++)
    	{
    		cout<<"\n Enter the ARIVAL TIME of P"<<i+1<<": ";
    		cin>>AT[i];
    		p[i]=i+1;
    		cout<<" Enter the BURST TIME of P"<<i+1<<": ";
    		cin>>BT[i];
		}
		sort();
	}
	
	void sort()                        // to sort the process with acending order of arrival time
	{
		for(i=0;i<n;i++)
		{		
			for(j=i+1;j<n;j++)
			{
				if(AT[i]>AT[j])
				{
					temp =AT[i];
					AT[i]=AT[j];
					AT[j]=temp;
					
					temp =BT[i];
					BT[i]=BT[j];
					BT[j]=temp;
					
					temp =p[i];
					p[i]=p[j];
					p[j]=temp;
				}
			}
		}
	}
	
	void display()
	{
		cout<<"\n Following is the table :- ";
		cout<<"\n | Process | Arival Time | Burst Time | Wating time | Turn around time |";
		x[0]=0;
		for(i=0; i<n; i++)
		{
			WT[i]=0;
			TAT[i]=0;
			x[i+1]=x[i]+BT[i];
			WT[i]=x[i]-AT[i];
			TAT[i]=WT[i]+BT[i];
			AWT+=WT[i];
			ATAT+=TAT[i];
			cout<<"\n      P"<<p[i]<<"       \t"<<AT[i]<<"        \t"<<BT[i]<<"        \t"<<WT[i]<<"\t\t"<<TAT[i];
		}
		cout<<"\n Average Wating Time: "<<AWT/n;
		cout<<"\n Average Turn Around Time: "<<ATAT/n;
	}
};

int main()
{
	FCFS A;
	A.getdata();
	A.display();
		
return 0;
}
