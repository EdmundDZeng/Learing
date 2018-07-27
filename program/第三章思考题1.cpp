#include<stdio.h>
#define INF  1000000000
int n[1000];

int main(){
	int i=0;
	int max=-INF,min=INF;
	int sum=0; 
	int avg;
	int sub=INF;
	int d2,d1;
	for(;;){
		scanf("%d",&n[i]);
		i++;               //统计个数
		if(n[i]>max) max=n[i];     //最大值 
		if(n[i]<min) min=n[i];     //最小值
		sum+=n[i];
		avg=sum/i;                //平均数
		if(i>=2){
			for(int d=1;d<=i-1;d++)
			if(n[d]-n[d-1]<sub) {
			sub=n[d]-n[d-1];       //那两个数最接近
			d2=d;
			d1=d2-1;
		} 
	}
	
	
}
return 0;
}
