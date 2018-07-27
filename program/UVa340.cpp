#include<stdio.h>

int main(){
	int n,kase=1;
	int A,B;
		int a[1010];
		int b[1010];
	while(scanf("%d",&n)==1&&n){
		printf("Game %d:\n",kase++);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(;;){
		A=0;
		B=0;
		for(int i=0;i<n;i++) {
			scanf("%d",&b[i]);
			if(a[i]==b[i]) A++;			
		}
		if(b[0]==0) break;
		for(int d=1;d<=9;d++){
			int c1=0;
			int c2=0;
			for(int i=0;i<n;i++){
				if(a[i]==d) c1++;
				if(b[i]==d) c2++;
			}
			if(c1<c2) B=B+c1;
			else B=B+c2;
		}
		printf("    (%d,%d)\n",A,B-A);
	}
}
return 0;
}
