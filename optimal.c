#include<stdio.h>
#include<limits.h>
int ls(int a[],int n){
	for(int i=0;i<3;i++){
		if(a[i]==n)	
			return i;
	}
	return -1;
}
int lsa(int k,int a[],int c,int n){
	int index=-1;
	for(int i=c;i<n;i++){
		if(a[i]==k)
			index=i;
	}
	return index;
}
int main(){
	int n;
	printf("enter the length of the reference string:");
	scanf("%d",&n);
	int a[100];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int frame[4];
	for(int i=0;i<3;i++){
		frame[i]=-1;
	}
	int count=0,max=-1;
	int hit=0,j=0,k,value;
	for(int i=0;i<n;i++){
		if(count<3){
			k=ls(frame,a[i]);
			if(k==-1){
				frame[j++]=a[i];
				count++;
			}
			else{
				hit++;
			}
		}
		else{
			max=-1;
			k=ls(frame,a[i]);
			if(k!=-1){
				hit++;
			}
			else{
				for(int m=0;m<3;m++){
					int s=lsa(frame[m],a,i,n);
					if(s>max){
						value=frame[m];
						max=s;
					}
				}
				k=ls(frame,value);
				frame[k]=value;
				//count++;
			}
			//count++;
			max=-1;
		}
		for(int j=0;j<3;j++){
			printf("%d  ",frame[j]);
		}
		printf("\n");
	}
	printf("%d\n",hit);
	
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1	
               
               			
				
					
