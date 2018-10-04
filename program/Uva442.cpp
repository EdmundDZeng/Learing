#include<cstdio>
#include<iostream>
#include<stack>
#include<map>
#include<string>
#include<cstring>
using namespace std;

int const maxn=26+5;

//typedef struct mat{
//	int row,column;
//	char id;
//	mat(const char& s,const int& x,const int& y):id(s),row(x),column(y){}
//}mats[maxn];

class node{
	public:
	int row,column;
	node(){}
	node(const int& x,const int& y):row(x),column(y){}
	bool operator<(const node &a)const{
		return this->row<a.row||(this->row==a.row&&this->column<a.column);
	}
};

map<char,node> mats;
bool flag=true;


int main(){
	int n,x,y;
	char s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s>>x>>y;
		node temp(x,y);
		if(!mats.count(s)) mats[s]=temp;
	}
	string exp;                  //表达式字符串
	while(cin>>exp){
		int cal=0;
		stack<char> exps;
		for(int i=0;i<exp.length();i++){
		 flag=true;
		if(exp[i]=='(') exps.push(exp[i]);
		else if(exp[i]==')'){
			char B=exps.top();
			exps.pop();
			char A=exps.top();
			if(mats[A].column!=mats[B].row) {
				    flag=false;
			        break;
			    }
			exps.pop();
			exps.pop();    //弹出'(' 
			cal+=mats[A].row*mats[A].column*mats[B].column;
			char C='a'+i;
		    node temp(mats[A].row,mats[B].column);
		    mats[C]=temp;
		    exps.push(C);
		}
		else exps.push(exp[i]);
	}
	if(flag) cout<<cal<<endl;
	else cout<<"error"<<endl;
	}
} 
