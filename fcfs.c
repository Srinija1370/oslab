#include<stdio.h>
struct point{
	int a;
	int b;
};
struct point sort(struct point p[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(p[i].a>p[j].a){
				struct point t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
}
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}	
int main(){
	struct point p[100];
	int n;
	printf("enter the number of processes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&p[i].a,&p[i].b);
	}
	sort(p,n);
	printf("the processes after sorting are....\n");
	for(int i=0;i<n;i++)
		printf("%d %d\n",p[i].a,p[i].b);
	int ct[100],wt[100],tat[100],awt=0,atat=0;
	ct[0]=p[0].a+p[0].b;
	for(int i=1;i<n;i++){
		ct[i]=max(ct[i-1],p[i].a)+p[i].b;
	}
	for(int i=0;i<n;i++){
		tat[i]=ct[i]-p[i].a;
		wt[i]=tat[i]-p[i].b;
		atat+=tat[i];
		awt+=wt[i];
	}
	printf("AT\t BT\t CT\t WT\t TAT\n");
	for(int i=0;i<n;i++)
		printf("%d\t %d\t %d\t %d\t %d\n",p[i].a,p[i].b,ct[i],wt[i],tat[i]);
	printf("the average waiting time is %f",(float)awt/n);
	printf("\nthe average turn around time is %f",(float)atat/n);
		
}
