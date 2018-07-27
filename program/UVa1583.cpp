#include<stdio.h>
#define maxn 100005
#include<string.h>
int ans[maxn];
int main(){
	int n;
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=100000;i++){
		int x=i,y=i;
		while(x>0){
			y+=x%10;
			x=x/10;
		}
		if(ans[y]==0||i<ans[y]) ans[y]=i;
	}
	while(scanf("%d",&n)==1&&n>=1&&n<=100000){
		printf("%d\n",ans[n]);
	}
return 0;
}
