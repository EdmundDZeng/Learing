#include<stdio.h>
int main()
{
	int a,b,c;
	int kase=0;
	while(scanf("%d%d%d",&a,&b,&c)==3&&((a+b+c)!=0))    //乘10取余 
	{
		kase++;
		int n=a/b;                        //整数部分
		printf("Case %d: %d.",kase,n);
		for(int i=1;i<=c-1;i++)            //c-1位小数部分 
		{
			a=a%b;
			a=a*10;
			printf("%d",a/b);
		}
		//第c位需要四舍五入
		a=a%b;                     //此时a为c-1位的余数
		int x=((a*10)%b*10)/b;      //第c+1位的小数位
		if(x>=5) printf("%d\n",(a*10)/b+1);
		else printf("%d\n",(a*10)/b);
	}
	return 0;

}
