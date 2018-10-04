#include<iostream>
#include<sstream>
#include<map> 
#include<vector>
#include<set>
#include<cstdio>
using namespace std;


int n,m;

map<string,set<int> > hash1;     //行数映射 
map<int,int>  hash2;             //文章数映射 
int main(){
	cin>>n;
	string pass[1505];   //存放文章 
	vector<int> rec;     //记录文章最后对应的行数 
	string s;
	cin.ignore();
	int line=0;
	for(int i=1;i<=n;i++){
		rec.push_back(line);
	while(getline(cin,s)&&s!="**********"){
		pass[line]=s;
		for(int i=0;i<s.length();i++){
			if(isalpha(s[i])) s[i]=tolower(s[i]);
			else s[i]=' ';
		}
		stringstream ss(s);
		string buf;
		while(ss>>buf){
			set<int> m;
			m.insert(line);
			if(!hash1.count(buf)) hash1[buf]=m;
			else hash1[buf].insert(line);
		}
		line++;
	}
}
    rec.push_back(sizeof(pass)/sizeof(string));
    for(int i=0;i<sizeof(pass)/sizeof(string);i++){
    	for(int j=0;j<rec.size()-1;j++){
    		if(rec[j]<=i&&i<rec[j+1]) hash2[i]=j+1;
		}
	}
    
	cin>>m;
	cin.ignore();
	while(m--){
		string A,B;
		getline(cin,s);
		if(s.find("NOT")!=string::npos){
			int p=s.find("NOT");
			A=s.substr(p+4);
			bool hashA;
			int flag=0;
			for(int i=1;i<=n;i++){
				hashA=false;
				for(int j=rec[i-1];j<rec[i];j++){
					if(hash1[A].count(j)) hashA=true;
				}
				if(!hashA){
					flag++;
					if(i>1&&flag!=1) cout<<"---------"<<endl;
					for(int j=rec[i-1];j<rec[i];j++){
						if(pass[j].empty()) break;
						cout<<pass[j]<<endl;					
						}
				}
				else if(flag==0&&i==n) cout<<"Sorry, I found nothing."<<endl;
				if(i==n) cout<<"=========="<<endl;
			}
		}
		else if(s.find(" AND ")!=string::npos){
			int p=s.find(" AND ");
			A=s.substr(0,p);
			B=s.substr(p+5);
			bool hashA,hashB;
			int flag=0;
			for(int i=1;i<=n;i++){
				hashA=false;hashB=false;
				for(int j=rec[i-1];j<rec[i];j++){
					if(hash1[A].count(j)) hashA=true;
					if(hash1[B].count(j)) hashB=true;
				}
				if(hashA&&hashB){
					flag++;
					if(i>1&&flag!=1) cout<<"---------"<<endl;
					for(int j=rec[i-1];j<rec[i];j++){
						if(pass[j].empty()) break;
						if(hash1[A].count(j)) { cout<<pass[j]<<endl;continue;}
						if(hash1[B].count(j)) { cout<<pass[j]<<endl;continue;}
					}
				}
				else if(flag==0&&i==n) cout<<"Sorry, I found nothing."<<endl;
				if(i==n) cout<<"=========="<<endl;
			}
		}
		else if(s.find(" OR ")!=string::npos){
			int p=s.find(" OR ");
			A=s.substr(0,p);
			B=s.substr(p+4);
			bool hashA,hashB;
			int flag=0;
			for(int i=1;i<=n;i++){
				hashA=false;hashB=false;
				for(int j=rec[i-1];j<rec[i];j++){
					if(hash1[A].count(j)) hashA=true;
					if(hash1[B].count(j)) hashB=true;
				}
				if(hashA||hashB){
					flag++;
					if(i>1&&flag!=1) cout<<"---------"<<endl;
					for(int j=rec[i-1];j<rec[i];j++){
						if(pass[j].empty()) break;
						if(hash1[A].count(j)) { cout<<pass[j]<<endl;continue;}
						if(hash1[B].count(j)) { cout<<pass[j]<<endl;continue;}
					}
				}
				else if(flag==0&&i==n) cout<<"Sorry, I found nothing."<<endl;
				if(i==n) cout<<"=========="<<endl;
			}
		}
		else {
			A=s;
			bool hashA;
			int flag=0;
			for(int i=1;i<=n;i++){
				hashA=false;
				for(int j=rec[i-1];j<rec[i];j++){
					if(hash1[A].count(j)) hashA=true;
				}
				if(hashA){
					flag++;
					if(i>1&&flag!=1) cout<<"---------"<<endl;
					for(int j=rec[i-1];j<rec[i];j++){
						if(pass[j].empty()) break;
						if(hash1[A].count(j)) { cout<<pass[j]<<endl;continue;}
					}
				}
				else if(flag==0&&i==n) cout<<"Sorry, I found nothing."<<endl;
				if(i==n) cout<<"=========="<<endl;
			}
		}
	}
	return 0;
} 
