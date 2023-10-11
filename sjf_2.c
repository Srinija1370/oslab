#include<stdio.h>
void sort(int at[],int bt[],int n)
{
	int tempa,tempb;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(at[j]>at[j+1])
			{
				tempa=at[j];
				at[j]=at[j+1];
				at[j+1]=tempa;
				
				tempb=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=tempb;
			}
		}
	}
}
int main()
{
	int n;
	printf("Enter No.of Process");
	scanf("%d",&n);
	int at[n];
	int bt[n];
	printf("Enter Arrival Times: ");
	int visited[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
		visited[i]=-1;
	}
	printf("Enter Burst Times");
	for(int i=0;i<n;i++)
		scanf("%d",&bt[i]);
	sort(at,bt,n);
	int ct[n];
	ct[0]=at[0]+bt[0];
	visited[0]=1;
	for(int i=1;i<n;i++)
	{
		int temp=-1;
		int temp_ind=-1;
		for(int j=0;j<n;j++)
		{
			if(at[j]<=ct[i-1] && visited[j]==-1)
			{
				if(temp==-1)
				{
					temp=bt[j];
					temp_ind=j;
				}
				else
				{
					if(temp>bt[j])
					{
						temp=bt[j];
						temp_ind=j;
					}
					
				}
			}
		}
		if(temp_ind!=-1)
		{
			visited[temp_ind]=1;
			ct[i]=ct[i-1]+temp;
		}
		else
		{
			ct[i]=at[i]+bt[i];
			visited[i]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d	%d	%d\n",at[i],bt[i],ct[i]);
	}
	
}
