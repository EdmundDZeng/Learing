#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;
struct dup{
	int x;
	int y;
	dup(int x,int y):x(x),y(y){ }
	bool operator < (const dup& r) const{
		return x<r.x||x==r.x&&y<r.y;
	}
};

int const maxn=10000+5;
int const maxm=10+5;
int database[maxn][maxm];
map<string,int> IDcache;
map<dup,int> Dic;
int c1,c2,r,r1;
int n,m;


void read(int x,int y){ //x:行,y:列 
    for(int i=0;i<x;i++)
    for(int j=0;j<y;j++){
    	char c;
    	string s;
    	while(c=getchar()){
    		if(c=='\n'||c==',') break;
			else {
				s+=c;
			} 
		}
		if(!IDcache.count(s)) IDcache[s]=(i+1)*10+(j+1);
		database[i][j]=IDcache[s];
	}
}

int look_for(){
	for(c1=1;c1<=m-1;c1++)
		for(c2=c1+1;c2<=m;c2++){
			for(r=1;r<=n;r++){
				dup data(database[r-1][c1-1],database[r-1][c2-1]);
				if(!Dic.count(data)) Dic[data]=r;
				else{
					r1=Dic[data];     //r1<r
					return 1;
				}
			}
		}
		return 0;
}

int main(){
	while(cin>>n>>m){
	    getchar();    //消除m,n输入后的回车符 
		read(n,m);
		if(look_for()) {
			cout<<"NO"<<endl;
			cout<<r1<<" "<<r<<endl;
			cout<<c1<<" "<<c2<<endl;
		}
		else cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		database[i][j]=0;
		Dic.clear();
		IDcache.clear();
	}
	return 0;
}
