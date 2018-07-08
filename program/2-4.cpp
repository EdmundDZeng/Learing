#include<stdio.h>
int main()
{
	int n,m;
	int kase=0;
	while(scanf("%d%d",&n,&m)==2&&((m+n)!=0))
	{
		kase++;
		double sum=0;
		for(long long int i=n;i<=m;i++) sum=sum+1/(double)(i*i);
		printf("Case %d: %.5f\n",kase,sum);
	}
}
