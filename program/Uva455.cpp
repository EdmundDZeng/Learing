#include<stdio.h>
#include<string.h>
#define maxn 85
char s[maxn];
int main(){
	int T;
	scanf("%d",&T);
	int m=T;
	printf("\n");
	while(T--){
		int c;
		int count=0;
		int Per=0;
		if(T==m-1) c=getchar();
		while((c=getchar())!='\n'){
			count++;
			s[count-1]=c;
			if(s[count-1-Per]!=s[count-1]) Per=count;
			else if(Per==0) Per++;
		}
		printf("%d\n\n",Per);
		if(T>0) printf("\n");

	}
	return 0;
}
