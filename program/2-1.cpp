#include<stdio.h>
int main()
{
	FILE *fin;
	fin = fopen("hanxin.txt","rb");
	int a,b,c,kase=0;
	while(fscanf(fin, "%d%d%d",&a,&b,&c)==3)
	{
		int i=0;
		kase++;
		if(a>=3||b>=5||c>=7) printf("Case %d: No answer\n",kase);
		for(int n=10;n<=100;n++)
		{
			i=n;
			if(n%3==a&&n%5==b&&n%7==c) 			
			{	
			printf("Case %d: %d\n",kase,n);
			break;
			}			
	    }
	    if(i==100) printf("Case %d: No answer\n",kase);
	}
	return 0;
}
