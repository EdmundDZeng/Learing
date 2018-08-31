#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;
int const DQ=1000000;
struct player{
	int rd[4];
	int total2,total4;
	string place;
	double money;
	bool amateur;
	string name;
};
int const maxn=75;
player p1[145];

int count;
double prize;
double scale[maxn];

int str_to_num(const string &s){
	int d=0;
	for(string::const_iterator it=s.begin();it!=s.end();it++)
	d=d*10+(*it-"0");
	return d;
}

int cmp2(const player &a,const player &b){
	if(a.total2!=b.total2) return a.total2<b.total2;
	else return a.name<b.name;
}
int cmp4(const player &a,const player &b){
	if(a.total4!=b.total4) return a.total4<b.total4;
	else return a.name<b.name;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>prize;
		for(int i=0;i<70;i++)
		cin>>scale[i];
		cin>>count;
		string in;
		getline(cin,in);
		for(int i=0;i<count;i++){
			getline(cin,in);
			//处理名字
			p1[i].name=in.substr(0,20);
			in=in.substr(20,in.size());
			//处理分数
			istringstream ss(in);
			p1[i].rd[0]=p1[i].rd[1]=p1[i].rd[2]=p1[i].rd[3]=DQ;
			p1[i].total2=p1[i].total4=0;
			for(int i=0;i!=4;i++){
				ss>>in;
				if(in=="DQ") break;
				else p1[i].rd[i]=str_to_num(in);
			}
			for(int i=0;i!=2;++i) p1[i].total2+=p1[i].rd[i];
			for(int i=0;i!=4;++i) p1[i].total4+=p1[i].rd[i];
			//是否业余 
			for(string::reverse_iterator it=p1[i].name.rbegin();it!=p1[i].name.rend();++it)
			if(*it!=' '){
				if(*it=='*') p1[i].amateur=true;
				else p1[i].amateur=false;
				break;
			}
		}
		sort(p1,p1+count,cmp2); //以前两轮排序 
		int last=p1[69].total2;
		int d=70;
		while(p1[d].total2==last) ++d;
		sort(p1,p1+d,cmp4);    //d名选手晋级下一轮并排序
		for(int i=0;i<d&&p1[i].total4<DQ;i++){   //处理名次与奖金 
			int m=i;
			int pro=0;
			ostringstream ss;
			ss<<(i+1);
			p1[i].place=ss.str();
			while(p1[m].total4==p1[m+1].total4){ 
			    if!(p1[m].amateur) pro++;
				p1[++m].place=ss.str();
			}
			if(pro>=2) while(i!=m+1){
				if(!p1[i].amateur) p1[i].place+='T';
				i++;
			}
			for(int j=i;j<=m;j++){
				if(p1[j].amateur&&pro==0){
					for(int i=j;i<70;i++) scale[j+1]=scale[j];
				}
				if(!p1[j].amateur&&pro!=0) p1[j].money=prize*scale[i+1]/pro;
				else p1[j].money=-1; 
			}
			i=m;
		}
		cout << "Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won" << '\n';
		cout << "-----------------------------------------------------------------------" << endl;
		
		
		
	}
}
