#include<stdio.h>
#define maxn 100000000
	int num[maxn];
	int rg[maxn];
int main(){
	long int a,b;
	while(scanf("%d %d",&a,&b)==2){
		int A=a/b;
		int m=a-A*b;
		int c,r;
		int count=0;
		int rc=1;     //���� 
		r=m%b;     //����
		rg[0]=r; 
		for(;;){
		c=r*10/b;      //С��һλ 
		r=r*10%b;
		num[count++]=c;    //С����¼ 
		rg[count]=r;      //������¼ 
		if(r==0) {   //������ 
			printf("%d/%d = %d.",a,b,A);
			for(int i=0;i<count;i++){
				printf("%d",num[i]);
			}
			printf("(0)\n");
			printf("   1 = number of digits in repeating cycle\n");
			break;
		}
		else {
			int flag;
		for(int i=count-1;i>=0;i--){
			flag=i;                         //flag���i�ı�� 
			if(rg[count]==rg[i]) {
			rc=count-i;
			
			break;
		}
		}
		if(rg[count]!=rg[flag]) continue;      //û���ҵ����� 
		printf("%d/%d = %d.",a,b,A);
		for(int i=0;i<=count-rc-1;i++)
		printf("%d",num[i]);
		printf("(");
		if(rc>50){
			for(int i=count-rc;i<count-rc+50;i++)
			printf("%d",num[i]);
			printf("...");
			printf(")\n");
			printf("   %d = number of digits in repeating cycle\n",rc);
			break;
		}
		else{
		for(int i=count-rc;i<=count-1;i++){
			printf("%d",num[i]);
		}
			printf(")\n");
			printf("   %d = number of digits in repeating cycle\n",rc);
			break;
		}
		 
	}
}
}
return 0;
}
