#include<stdio.h>
#include<string.h>
int count[10]={0};
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			count[i%10]++;
			if(i/10!=0) count[i/10%10]++;
			if(i/100!=0) count[i/100%10]++;
			if(i/1000!=0) count[i/1000%10]++;
		}
		int i=0;
		for(;i<=8;i++){
			printf("%d ",count[i]);
		}
		printf("%d\n",count[i]);
		memset(count,0,sizeof(count));
	}
	return 0;
}
