#include<stdio.h>
int ls(int n,int a[]){
	for(int i=0;i<3;i++){
		if(a[i]==n)	
			return i;
	}
	return -1;
}
int main(){
	int n;
	printf("enter the number of strings:");
	scanf("%d",&n);
	int a[100];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int frame[3];
	for(int i=0;i<3;i++){
		frame[i]=-1;
	}
	int count=0,hit=0;
	for(int i=0;i<n;i++){
		int k=ls(a[i],frame);
		if(k==-1){
			frame[count%3]=a[i];
			count++;
		}
		else{
			hit++;
		}
		for(int j=0;j<3;j++){
			printf("%d ",frame[j]);
		}
		printf("\n");
	}
	printf("%d\n",hit);
	float f=(float)(hit*100)/n;
	printf("%.2f",f);
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

