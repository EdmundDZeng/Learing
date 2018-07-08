#include<stdio.h>
int main(){
	int n,m;          //n位原来的三位数，m位倒置后的三位数 
	scanf("%d",&n);
	m=(n%10)*100+(n/10%10)*10+(n/100);
	printf("%03d\n",m);
	return 0; 
}
