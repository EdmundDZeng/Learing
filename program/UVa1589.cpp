#include<stdio.h>
#include<string.h> //黑方先移动
struct chess{
	int x,y;
	char type;
}ch[10];

 char chessBor[11][11];   //棋盘 
 int N;
 int B_x,B_y;
 int twice;


 
 int checkHorse(int x,int y){
 	 if(x-1>=1){
 		if(chessBor[x-1][y-2]=='H'&&chessBor[x-1][y-1]==0) return 1;
 		if(chessBor[x-1][y+2]=='H'&&chessBor[x-1][y+1]==0) return 1;
	 }
	 if(x-2>=1){
 		if(chessBor[x-2][y-1]=='H'&&chessBor[x-1][y-1]==0) return 1;
		if(chessBor[x-2][y+1]=='H'&&chessBor[x-1][y+1]==0) return 1;	
	 }
	 if(chessBor[x+1][y-2]=='H'&&chessBor[x+1][y-1]==0) return 1;
	 if(chessBor[x+2][y-1]=='H'&&chessBor[x+1][y-1]==0) return 1;
 	 if(chessBor[x+1][y+2]=='H'&&chessBor[x+1][y+1]==0) return 1;
 	 if(chessBor[x+2][y+1]=='H'&&chessBor[x+1][y+1]==0) return 1;
	 return 0;
 }
 
 int check(){
 	int flag=0;
 	for(int i=B_y;i>=1;i--){
 		if(chessBor[B_x][i]==0) continue;     //没有棋子
		else{
			flag++;
			if(flag==1&&chessBor[B_x][i]=='R') return 1;
			if(flag==2&&chessBor[B_x][i]=='C') return 1;
			if(flag>=3) break;
		}
	}
	 flag=0;
	for(int i=B_y;i<=9;i++) {
 		if(chessBor[B_x][i]==0) continue;     //没有棋子
		else{
			flag++;
			if(flag==1&&chessBor[B_x][i]=='R') return 1;
			if(flag==2&&chessBor[B_x][i]=='C') return 1;
			if(flag>=3) break;
		}
	 }
	 flag=0;
	for(int j=B_x;j>=1;j--){
		if(chessBor[j][B_y]==0) continue;     //没有棋子
		else{
			flag++;
			if(flag==1&&chessBor[j][B_y]=='R') return 1;
			if(twice==2&&chessBor[j][B_y]=='G') return 1;
			if(twice==1&&chessBor[j][B_y]=='G') break;
			if(flag==2&&chessBor[j][B_y]=='C') return 1;
			if(flag>=3) break;
		}
	}
	flag=0;
	for(int j=B_x;j<=10;j++){
		if(chessBor[j][B_y]==0) continue;     //没有棋子
		else{
			flag++;
			if(flag==1&&chessBor[j][B_y]=='R') return 1;
			if(twice==2&&chessBor[j][B_y]=='G') return 1;
			if(twice==1&&chessBor[j][B_y]=='G') break;
			if(flag==2&&chessBor[j][B_y]=='C') return 1;
			if(flag>=3) break;
		}
	}
	if(checkHorse(B_x,B_y)) return 1;
	else return 0;
 }
 
 int twice_check(int x,int y){
	char m=chessBor[x][y];
	chessBor[x][y]=0;          //旗子被吃掉 
	if(!check()){
	 printf("NO\n");
	 chessBor[x][y]=m;        //棋盘复原 
	 return 0;
}
else return 1;
}

int main(){
	while(scanf(" %d%d%d",&N,&B_x,&B_y)==3&&(N||B_x||B_y)){
		memset(chessBor,0,sizeof(chessBor));
		memset(ch,0,sizeof(chess)*10);
		for(int i=0;i<N;i++){
			scanf(" %c %d %d",&(ch[i].type),&ch[i].x,&ch[i].y);
			chessBor[ch[i].x][ch[i].y]=ch[i].type;
		}
		twice=1;
		if(check()) {
			twice=2;
			int i=B_x;
			int j=B_y;
			if(B_x-1>=1){
				if(!twice_check(--B_x,B_y)) continue;
			}
			B_x=i;
			if(B_x+1<=3){
				if(!twice_check(++B_x,B_y)) continue;
			}
			B_x=i;
			if(B_y-1>=4){
				if(!twice_check(B_x,--B_y)) continue;
			}
			B_y=j;
			if(B_y+1<=6){
				if(!twice_check(B_x,++B_y)) continue;
			}
			B_y=j;
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}
