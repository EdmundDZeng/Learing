#include<stdio.h>
#define maxn 10
char Frame[maxn][maxn];

void Change(char& x,char& y){
	char temp=y;
	y=x;
	x=temp;
}

int main(){
	int flag=0;
	int x=0,y=0;
	int kase=0;
	int c;
	int error=0;
	for(;;){
	fflush(stdin);
	kase++;
	//printf("Puzzle #%d:\n",kase);
	for(int i=0;i<5;i++){
		int j=0;
		while((c=getchar())!='\n')
		Frame[i][j++]=c;

	if(Frame[i][0]=='Z') {
		flag=i;
		break;
	}
}
    if(Frame[flag][0]!='Z'){
    	while((c=getchar())!='0'){
    	if (c=='\n') continue;
    	else {
    		for(int i=0;i<5;i++)
    		for(int j=0;j<5;j++){	
    		if(Frame[i][j]==' '){
			x=i;
			y=j;
		}
	}
    		if(c=='A') {
    		if(x-1<0)  error=1;
			Change(Frame[x][y],Frame[x-1][y]);
			}
			else if(c=='B') {
    		if(x+1>4) error=1;
			Change(Frame[x][y],Frame[x+1][y]);
			}
			else if(c=='L') {
    		if(y-1<0) error=1;
			Change(Frame[x][y],Frame[x][y-1]);
			}
			else if(c=='R') {
    		if(y+1>4) error=1;
			Change(Frame[x][y],Frame[x][y+1]);
			}
		}
	}
		printf("Puzzle #%d:\n",kase);
	if(error=1) {
	printf("This puzzle has no final configuration.\n");
//	if(Frame[flag][0]!='Z') printf("\n");
}
	else {
		for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
		{
			if(j<4)
			printf("%c ",Frame[i][j]);
			else printf("%c\n",Frame[i][j]);
		}
//		if(i==4) {
	//		if(Frame[flag][0]!='Z') printf("\n");
	//	}
	}
	}
	
}
    else break;
}
	return 0;
}
