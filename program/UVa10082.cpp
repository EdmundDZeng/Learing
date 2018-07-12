
#include<stdio.h>
char s[] ="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main(){
	int c,i;
	while((c=getchar())!=EOF) {
		i=1;
		if(c==' ') putchar(c);
		else if(c=='\n') printf("\n");
		else{
			while(s[i]&&s[i]!=c) i++;
			if(s[i]) {
			putchar(s[i-1]);
			break;
		}
		}
	}
	return 0;
}




