#include<stdio.h>
struct process{
	int p,p_size;
};
int sort(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
int main(){
	int n;
	struct process pro[100];
	printf("enter the number of process:");
	scanf("%d",&n);
	int b[10];
	printf("enter the process id and processor size:");
	for(int i=0;i<n;i++){
		scanf("%d%d",&pro[i].p,&pro[i].p_size);
	}
	printf("enter the block size:");
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	sort(b,n);
	for(int i=0;i<n;i++){
		printf("%d \t",b[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pro[i].p_size<=b[j]){
				printf("%d %d %d\n",pro[i].p,pro[i].p_size,b[j]);
				b[j]=-1;
				break;
			}
		}
	}
}
	
