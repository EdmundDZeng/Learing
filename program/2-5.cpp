#include<stdio.h>
int main()
{
	int a,b,c;
	int kase=0;
	while(scanf("%d%d%d",&a,&b,&c)==3&&((a+b+c)!=0))    //��10ȡ�� 
	{
		kase++;
		int n=a/b;                        //��������
		printf("Case %d: %d.",kase,n);
		for(int i=1;i<=c-1;i++)            //c-1λС������ 
		{
			a=a%b;
			a=a*10;
			printf("%d",a/b);
		}
		//��cλ��Ҫ��������
		a=a%b;                     //��ʱaΪc-1λ������
		int x=((a*10)%b*10)/b;      //��c+1λ��С��λ
		if(x>=5) printf("%d\n",(a*10)/b+1);
		else printf("%d\n",(a*10)/b);
	}
	return 0;

}
