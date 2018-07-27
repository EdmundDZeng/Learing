#include<stdio.h>
#include<string.h>
#define maxn 85
double gmol[]={12.01,1.008,16.00,14.01};
char s[maxn];
double  a[10]={0};

int main(){
	int T;
	int c;
	double M=0;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int j;     
		for(int i=0;i<strlen(s);){
			if(s[i]>='A'&&s[i]<='Z'){
				j=i;
				if(s[++j]>'0'&&s[j]<='9'){
					a[0]=s[j]-'0';
					if(s[++j]>'0'&&s[j]<='9'){
						a[1]=s[j]-'0';
						j++;
					}
				}
			}
		if(s[i]=='C') {
			if(a[1]==0&&a[0]==0) M+=gmol[0];
			if(a[1]==0&&a[0]!=0) M+=gmol[0]*a[0];
			else M+=gmol[0]*(a[0]*10+a[1]);
		}
		if(s[i]=='H') {
			if(a[1]==0&&a[0]==0) M+=gmol[1];
			if(a[1]==0&&a[0]!=0) M+=gmol[1]*a[0];
			else M+=gmol[1]*(a[0]*10+a[1]);
		}
		if(s[i]=='O') {
			if(a[1]==0&&a[0]==0) M+=gmol[2];
			if(a[1]==0&&a[0]!=0) M+=gmol[2]*a[0];
			else M+=gmol[2]*(a[0]*10+a[1]);
		}
		if(s[i]=='N') {
			if(a[1]==0&&a[0]==0) M+=gmol[3];
			if(a[1]==0&&a[0]!=0) M+=gmol[3]*a[0];
			else M+=gmol[3]*(a[0]*10+a[1]);
		}
		i=j;
		a[0]=0;a[1]=0;		
				
		}
		printf("%.3f\n",M);
		M=0;
	}
	return 0;
}
