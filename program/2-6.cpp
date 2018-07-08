#include<stdio.h>
void test(int t[],int m)
{
	t[m%10]++;               //m对应的个位数字
	t[m/10%10]++;             //m对应的十位数字
	t[m/100]++;                //m对应的百位数字 
}

int main()
{
	int j,k;                 //大的两位三位数 
	int p  ;                  
	int a[10]={0};
	for(int i=123;i<=333;i++)
	{
		j=2*i;
		k=3*i;
		test(a,i);
		test(a,j);
		test(a,k);
		for(p=1;p<=9;p++)
		{
			if(a[p]!=1) {
				for(int i=0;i<=9;i++)
				{
				a[i]=0;                 //只要不满足条件a[i]全部置零
			    }
			    break;
			}
			
		}
		if(p==10&&(a[0]==0)) printf("%d %d %d\n",i,j,k);
		
	}
	
	return 0;

}
