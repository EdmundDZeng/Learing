#include<stdio.h>

int main(){
	int c;
	int count;
	int count1=0;
	int score;
	int n;
	scanf("%d",&n);
	c=getchar();
	while(n--){
	count=0;
	score=0;
	while((c=getchar())!='\n'){
		if(c=='O') count++;
		if(c=='X') count=0;
		score=score+count;
	}
	if(n>=1)
		printf("%d\n",score);
	else printf("%d",score);
	}

	return 0;
}
