#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s1[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* s2[]={"is not a palindrome.","is a regular palindrome.","is a mirrored string.","is a mirrored palindrome."};
char s[100];

int r(char ch){
	if(isalpha(ch)) return ch-'A';
	return ch-'0'+25;
}

int main(){
	int pa=1,mi=1,re=0;
	while(scanf("%s",s)==1){
		pa=1;mi=1;
		for(int i=0;i<strlen(s);i++){
		
		if(s[i]!=s[strlen(s)-i-1]){
			pa=0;
		}
		
		if(s[strlen(s)-i-1]!=s1[r(s[i])]){
			mi=0;
		}
	}
	if(pa==0&&mi==0) re=0;
	else if(pa==1&&mi==0) re=1;
	else if(pa==0&&mi==1) re=2;
	else if(pa==1&&mi==1) re=3;
	
	printf("%s -- %s\n",s,s2[re]);
	printf("\n");
	}
	return 0;
}
