#include<stdio.h>
#define maxn 100000000
	int num[maxn];
	int rg[maxn];
int main(){
	int a,b;
	while(scanf("%d %d",&a,&b)==2){
		int A=a/b;
		int m=a-A*b;
		int c,r;
		int count=0;
		int rc=1;     //���� 
		r=m%b;     //����
		int rs=r;       //��¼�ʼ������
		for(;;){
		rg[0]=rs; 
		c=r*10/b;      //С��һλ 
		r=r*10%b;
		num[count++]=c;    //С����¼ 
		rg[count]=r;      //������¼ 
		if(r==0) {   //������ 
			printf("%d/%d = %d.",a,b);
			for(int i=0;i<count;i++){
				printf("%d",num[i]);
			}
			printf("(0)\n");
			printf("   1 = number of digits in repeating cycle\n");
			break;
		}
		else {
		for(int i=count-1;i>=0;i--){
			if(rg[count]==rg[i]) rc=count-i;
		}
		printf("%d/%d = %d.",a,b);
		for(int i=0;i<count-1-rc;i++)
		printf("%d",num[i]);
		printf("(");
		if(rc>50){
			for(int i=count-1-rc;i<count-1-rc+50;i++)
			printf("%d",num[i]);
			printf("...");
			printf(")\n");
			printf("   %d = number of digits in repeating cycle\n",rc);
		}
		else{
		for(int i=count-1-rc;i<count-1;i++){
			printf("%d",num[i]);
		}
			printf(")\n");
			printf("   %d = number of digits in repeating cycle\n",rc);
		}
		 
	}
}
}
return 0;
}
