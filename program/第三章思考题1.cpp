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
		i++;               //ͳ�Ƹ���
		if(n[i]>max) max=n[i];     //���ֵ 
		if(n[i]<min) min=n[i];     //��Сֵ
		sum+=n[i];
		avg=sum/i;                //ƽ����
		if(i>=2){
			for(int d=1;d<=i-1;d++)
			if(n[d]-n[d-1]<sub) {
			sub=n[d]-n[d-1];       //����������ӽ�
			d2=d;
			d1=d2-1;
		} 
	}
	
	
}
return 0;
}
