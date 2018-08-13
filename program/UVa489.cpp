#include<stdio.h>
#include<string.h>
#define maxn 100
char s1[maxn],s2[maxn];
int win,lose;
int chance,left;

void guess(char ch){
	int bad=1;
	for(int i=0;i<strlen(s1);i++){
		if(ch==s1[i]){
			left--;
			s1[i]=' ';
			bad=0;
		}
	}
	if(bad) --chance;
	if(!chance) lose=1;
	if(!left) win=1;
}

int main(){
	int rnd;
	while(scanf("%d%s%s",&rnd,s1,s2)==3&&rnd!=-1){
		printf("Round %d\n",rnd);
		win=lose=0;
		left=strlen(s1);
		chance=7;
		for(int i=0;i<strlen(s2);i++){
			guess(s2[i]);
			if(win||lose) break;
		}
		if(win) printf("You win.\n");
		else if(lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
}
