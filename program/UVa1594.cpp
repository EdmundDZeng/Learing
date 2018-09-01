#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
set<vector<int> > duc;

int main(){
	int T,n,m;
	cin>>T;
	while(T--){
		duc.clear();
		cin>>n;
		vector<int> d;
		for(int i=0;i<n;i++){
		cin>>m;
		d.push_back(m);
	}
	duc.insert(d);
	for(;;){
		int tmp=d[0];
		for(int i=0;i<n;i++){
			if(i==n-1) d[i]=abs(d[i]-tmp);
			else d[i]=abs(d[i]-d[i+1]);
		}
		int flag=0;
		for(int i=0;i<n;i++){
			if(d[i]!=0) break;
			else flag++;
		}
		if(flag==n){
			cout<<"ZERO"<<endl;
			break;
		}
	if(duc.count(d)!=0){
		cout<<"LOOP"<<endl;
		break;
	}
	else{
		duc.insert(d);
	}
}
}
return 0;
}
