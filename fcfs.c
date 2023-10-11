#include<stdio.h>
void sort(int p[],int at[],int bt[],int n)
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
				
				int temp3=p[j];
				p[j]=p[j+1];
				p[j+1]=temp3;
			}
		}
	}
}
int completionTime(int at[],int bt[],int ct[],int n)
{
	ct[0]=at[0]+bt[0];
	for(int i=1;i<n;i++)
	{
		if(at[i]<=ct[i-1])
		{
			ct[i]=ct[i-1]+bt[i];
		}
		else
		{
			ct[i]=at[i]+bt[i];
		}
	}
}
void turnAroundTime(int tat[],int at[],int ct[],int n)
{
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
	}
}
void waitingTime(int wt[],int tat[],int bt[],int n)
{
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
}
float avgtat(int tat[],int n)
{
	float sum=0;
	for(int i=0;i<n;i++)
		sum=sum+tat[i];
	float avg=sum/n;
	return avg;
}
float avgwt(int wt[],int n)
{
	float sum=0;
	for(int i=0;i<n;i++)
		sum=sum+wt[i];
	float avg=sum/n;
	return avg;
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
	sort(p,at,bt,n);	
	printf("Gantt Chat processors order: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",p[i]);
	}
	completionTime(at,bt,ct,n);
	turnAroundTime(tat,at,ct,n);
	waitingTime(wt,tat,bt,n);
	float avgtatTime=avgtat(tat,n);
	float avgwtTime=avgwt(wt,n);
	printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	printf("\nAverage Turn around time: %f",avgtatTime);
	printf("\nAverage waiting time: %f",avgwtTime);
}
