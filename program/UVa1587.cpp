#include<stdio.h>
#include <algorithm>
void change(int& a,int& b){
	int j;
	j=a;
	a=b;
	b=j;
}

int main(){
	int c;
	for(;;){
		int T=6;
		int w[6];
		int h[6];
		int test[3]={0};
		int i;
		for(i=0;i<6;i++){
			if(scanf("%d%d",&w[i],&h[i])==EOF) break;
			if(w[i]<h[i]) change(w[i],h[i]);
			for(int j=i;j>=1;j--){         //按长排序 
				if(w[j]>w[j-1]){
					change(w[j],w[j-1]);
					change(h[j],h[j-1]);
				}
				if(w[j]==w[j-1]){          //长相等时按宽排序 
					if(h[j]>h[j-1]){
						change(h[j],h[j-1]);
					}
				}
			}
		}
		if(i!=6) break;
		int a=w[0];
		int b=h[0];
		int c=h[2];
		for(i=0;i<=3;i++){
		if(w[i]!=a) {
		printf("IMPOSSIBLE\n");
		break;
	}
		if(h[i+2]!=c) {
		printf("IMPOSSIBLE\n");
		break;
	}
	    if(i<=1){
	    		if(h[i]!=b) {
		printf("IMPOSSIBLE\n");
		break;
	}
		}
		else {
					if(w[i+2]!=b) {
		printf("IMPOSSIBLE\n");
		break;
	}
		}
	}
	    if(i==4) printf("POSSIBLE\n");
	
}
return 0;
}
