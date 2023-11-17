#include<bits/stdc++.h>
using namespace std;
struct atbt
{
   int at,bt;
   string p;
};
string a[100];
int front=-1;
int rear=-1;
//queue<string> q;
void enqueue(string q)
{
   if(front==-1 && rear==-1)
   {
      front=rear=0;
      a[front]=q;
   }
   else
   {
      rear++;
      a[rear]=q;
     
   }
 
}
void dequeue()
{
   if(front==rear)
   front=rear=-1;
   else
   {
     cout<<"deleted processor:"<<a[front]<<"\n";
     front++;
   }
   
}
  void sort(atbt arr[],int n)
  {
    for(int i=0;i<n-1;i++)
    {
      for(int j=0;j<n-i-1;j++)
      { 
         if(arr[j].at>arr[j+1].at)
         {
            atbt t=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=t;
         }
      }
    }
  }
  
void solve(atbt arr[],int n,int CT[],int ideal,int tq,atbt arr2[])
{
   int sum=ideal;
   int j=1;// already 1st element is completed
   enqueue(arr2[0].p);
   while(rear != -1 && front != -1 )
   {
     for(int i=0;i<n;i++)
     {
        if(a[front]==arr2[i].p)
        {
          if(arr2[i].bt<=tq)
          {
            sum+=arr2[i].bt;
            CT[i]=sum;
           
          }
          else
          {
             sum+=tq;
             arr2[i].bt-=tq;
             while(arr2[j].at<=sum && j<n)
             {
		     enqueue(arr2[j].p);
		     j++;
             }
             enqueue(arr2[i].p);
          }
          break;
        }
        
     }
     dequeue();
   }

}
  float average(int a[],int n)
  {
     float sum=0;
     for(int i=0;i<n;i++)
     {
        sum+=a[i];
     }
     return sum/n;
  }  
int main()
{
    int n;
    cout<<"enter the no. of processors:";
    cin>>n;
    atbt arr[n];
    cout<<"enter at,bt and processor  respectively:";
    for(int i=0;i<n;i++)
    cin>>arr[i].at>>arr[i].bt>>arr[i].p;
    sort(arr,n);
    cout<<"sorted atbt :"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i].p<<"\t"<<arr[i].at<<"\t"<<arr[i].bt<<endl;
    int CT[n],ideal=0,tq;
    cout<<"enter the time quantum:";
    cin>>tq;
    atbt arr2[n];
    for(int i=0;i<n;i++)
    arr2[i]=arr[i];
   if(arr[0].at==0)
     solve(arr,n,CT,ideal,tq,arr2);
     else
     {
        ideal=ideal+arr[0].at;
        solve(arr,n,CT,ideal,tq,arr2);
     }
     cout<<"compilition time is:\n";
   for(int i=0;i<n;i++)
   {
   cout<<arr[i].p<<" ";
   cout<<CT[i]<<endl;
   }
   int tat[n],wt[n];
   for(int i=0;i<n;i++)
   {
      tat[i]=CT[i]-arr[i].at;
      wt[i]=tat[i]-arr[i].bt; 
   }
   cout<<"\nturn around time:\n";
   for(int i=0;i<n;i++)
   {
     cout<<arr[i].p<<" ";
   cout<<tat[i]<<endl;
   }
   cout<<"\nwaiting time:\n";
   for(int i=0;i<n;i++)
   {
     cout<<arr[i].p<<" ";
   cout<<wt[i]<<endl;
   }
   cout<<"\naverage tat:"<<average(tat,n);
   cout<<"\naverage wt:"<<average(wt,n);
}

