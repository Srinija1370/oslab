#include<stdio.h>
void sort(int at[],int bt[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(at[j]>at[j+1])
			{
				int temp1=at[j];
				at[j]=at[j+1];
				at[j+1]=temp1;
				
				int temp2=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp2;
			}
		}
	}
}
void completionTime(int p[],int at[],int bt[],int ct[],int n)
{
			if(at[0]==at[1])//arrival times equal
			{
				if(bt[0]<bt[1])
					ct[0]=at[0]+bt[0];
				else
					ct[0]=at[0]+bt[1];
			}
			else	//if burst times equal
			{
				if(bt[0]==bt[1])
				{
					if(at[0]<at[1])	//check lesser arrival
						ct[0]=at[0]+bt[0];
					else
						ct[0]=at[0]+bt[1];
				}
				else if(at[0]==at[1]) //arrival and burst equal
				{
						if(p[0]<p[1])	//process order
							ct[0]=at[0]+bt[0];
						else
							ct[0]=at[0]+bt[1];
				}
			}
	for(int i=1;i<n;i++)
	{
		if(at[i]<=ct[i-1])//non-idle state
		{
			if(at[i]==at[i+1])//arrival times equal
			{
				if(bt[i]<bt[i+1])
					ct[i]=ct[i-1]+bt[i];
				else
					ct[i]=ct[i-1]+bt[i+1];
			}
			else	//if burst times equal
			{
				if(bt[i]==bt[i+1])
				{
					if(at[i]<at[i+1])	//check lesser arrival
						ct[i]=ct[i-1]+bt[i];
					else
						ct[i]=ct[i-1]+bt[i+1];
				}
				else if(at[i]==at[i+1]) //arrival and burst equal
				{
						if(p[i]<p[i+1])	//process order
							ct[i]=ct[i-1]+bt[i];
						else
						ct[i]=ct[i-1]+bt[i+1];
				}
			}
		}
		else //idle state
		{
			if(at[i]==at[i+1])//arrival times equal
			{
				if(bt[i]<bt[i+1])
					ct[i]=ct[i-1]+bt[i];
				else
					ct[i]=ct[i-1]+bt[i+1];
			}
			else	//if burst times equal
			{
				if(bt[i]==bt[i+1])
				{
					if(at[i]<at[i+1])	//check lesser arrival
						ct[i]=ct[i-1]+bt[i];
					else
						ct[i]=ct[i-1]+bt[i+1];
				}
				else if(at[i]==at[i+1]) //arrival and burst equal
				{
						if(p[i]<p[i+1])	//process order
							ct[i]=ct[i-1]+bt[i];
						else
						ct[i]=ct[i-1]+bt[i+1];
				}
			}
		}
	}
}
int main()
{
	int n;
	printf("enter number of processors: ");
	scanf("%d",&n);
	int at[n],bt[n],ct[n],tat[n],wt[n],p[n];
	printf("enter processors: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("enter arrival times: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("enter burst times: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	sort(at,bt,n);	
	//printf("Gantt Chat processors order: ");
	//for(int i=0;i<n;i++)
//	{
//		printf("%d ",p[i]);
//	}
	completionTime(p,at,bt,ct,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",ct[i]);
	}
//	turnAroundTime(tat,at,ct,n);
//	waitingTime(wt,tat,bt,n);
//	float avgtatTime=avgtat(tat,n);
//	float avgwtTime=avgwt(wt,n);
//	printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
//	for(int i=0;i<n;i++)
	//	printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
//	printf("\nAverage Turn around time: %f",avgtatTime);
//	printf("\nAverage waiting time: %f",avgwtTime);
}
