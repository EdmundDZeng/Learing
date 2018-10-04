#include<cstdio>
int main(){
	int dep,cout;
	int l;
	scanf("%d",&l);
	while(l--){
	scanf("%d %d",&dep,&cout);
		int k=1;
		for(int i=0;i<dep-1;i++){
			if(cout%2){
				k=k*2;
				cout=(cout+1)/2;     //Ò»°ëÇò+1È¥×ó×ÓÊ÷ 
			}
			else {
				k=k*2+1;
				cout/=2;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
