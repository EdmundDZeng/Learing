#include<stdio.h>
#define maxn 25
int n,k,m;
int que[maxn];
int select(int s,int d,int t){
	while(t--){
		do{
			s=(s+d+n-1)%n+1;
		}while(que[s]==0);
	}
	return s;
}
int main(){

	while(scanf("%d %d %d",&n,&k,&m)==3&&n){
			for(int i=1;i<=n;i++){
		que[i]=i;
	}
		int p1=n,p2=1;
		int left=n;
		while(left){
			p1=select(p1,1,k);
			p2=select(p2,-1,m);
			printf("%3d",p1);
			left--;
			if(p2!=p1) {
				printf("%3d",p2);
				left--;
			}
			que[p1]=que[p2]=0;
			if(left) printf(",");
		}
		printf("\n");
		
	}
	return 0;
}
