#include<stdio.h>
int main()
{
	int x,y,n;
	scanf("%d",&n);
	for(int i=n;i>=1;i--)
	{
		x=2*i-1;
		y=2*n-1-x;  //¿Õ¸ñ¸öÊý
		for(int i=1;i<=y/2;i++) printf(" ");
		for(int i=1;i<=x;i++) printf("*");
		for(int i=1;i<=y/2;i++) printf(" ");
		printf("\n");
	}
	return 0;
}
