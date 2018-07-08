#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n<=3) printf(".3f",95.0*n);
	else printf("%.3f",300.0+((n*95-300)*0.85));
	return 0;
}
