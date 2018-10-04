#include<stdio.h>
#define maxn 100000+5
int next[maxn];
int front[maxn];
void pop(int m)
void insert(int n,int i,int j)
int main(){
	int n,m,cmd;
	int kase=0;
	while(scanf("%d,%d",&n,&m)==2){
		kase++;
		for(int i=0;i<=n+1;i++){
			if(i==0) front[0]=0;
			else front[i]=i-1;
			if(i==n+1) next[i]=i;
			else next[i]=i+1;
		}
		while(m--){
			int X,Y;
			scanf("%d",&cmd);
			if(cmd==1){
				scanf("%d%d",&X,&Y);
				if(front[Y]==X) continue;
				else {
					pop(X);
					insert(X,front(Y),Y);
				}
			}
			else if(cmd==2){
				scanf("%d%d",&X,&Y);
				if(next[Y]==X) continue;
				else {
					pop(X);
					insert(X,Y,next[Y]);
				}
			}
			else if(cmd==3){
				scanf("%d%d",&X,&Y);
				pop(X);
				pop(Y);
				insert(X,front(Y),next(Y));
				insert(Y,front(X),next(X));
			}
			else if(cmd==4){
				int m=0;     //m和i分别一前一后 
				int i,temp;
				for(;;){
					i=next[m];
					next[m]=front[m];
					front[m]=i;       //m重新连接 
					temp=next[i];
					next[i]=m;
					m=i;
					front[i]=temp;
				}
			}
		}
	}
} 
