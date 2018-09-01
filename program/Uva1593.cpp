#include<string>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int const n=1005;
int i;
vector<string> a[n];
int space[185]={0};

void readword(){
	string s;
	char ch;
	i=0;
	while(cin>>s){
		cin.get(ch);
		a[i].push_back(s);
		if(ch=='\n') i++;
	}
}

void output(){
	for(int q=0;q<i;q++)
	for(int p=0;p<a[q].size();p++){
		cout<<a[q][p];
		if(p!=a[q].size()-1){
		int m=space[p]-a[q][p].size()+1;
		while(m--) cout<<' ';
	}
	else if(q!=i-1||p!=a[q].size()-1) cout<<endl;
		}
}

int main(){
	readword();
	for(int q=0;q<i;q++)
	for(int p=0;p<a[q].size();p++){
		if(space[p]<a[q][p].size()) space[p]=a[q][p].size();
	}
	output();
	return 0;
} 
