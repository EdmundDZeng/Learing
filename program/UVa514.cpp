#include<cstdio>
#include<stack>
using namespace std;
const int MAXN=1000+10;
int n,target[MAXN];


int main(){
	while(scanf("%d",&n)==1&&n!=0){
		for(;;){
			stack<int> s;
		int A=1,B=1;
		for(int i=1;i<=n;i++){
		scanf("%d",&target[i]);
		if(target[i]==0) { break;}
	}
	    if(target[1]==0) break;
		int ok=1;
		while(B<=n){
			if(A==target[B]){A++;B++;}
			else if(!s.empty()&&s.top()==target[B]) {s.pop();B++;}
			else if(A<=n) s.push(A++);
			else{ok=0;break;}
		}
		printf("%s\n",ok?"Yes":"No");
}

}
printf("\n");
return 0;
}
