#include<stdio.h>
#define maxn 100000000
#include<string.h>
char s[maxn];
char t[maxn];

int main(){
	while(scanf("%s %s",s,t)==2){
		int i,j;
		i=0;
		for(int j=0;j<strlen(t);j++){
			if(i>=strlen(s)) break;
			if(t[j]==s[i]) {
				if(i==strlen(s)-1) {
				printf("Yes\n");
				break;
			}
				else i++;
			}
			else {
				if(j==strlen(t)-1) {
				printf("No\n");
				break;
				}
				else continue;
			}
		}
		
	}
	return 0;
}
