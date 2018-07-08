#include<stdio.h>
int main(){
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) {
		t=a;a=b;b=t;
	}
	if(b>c){
		t=b;b=c;c=t;
	}
    if(a>b) {
		t=a;a=b;b=t;
	}
	if(c*c==(a*a+b*b)) {
	  printf("yes\n");
	  }
	else{
		if(c>=(a+b)) printf("not a triangle\n");
		else printf("no\n");
	}
	return 0;
} 
