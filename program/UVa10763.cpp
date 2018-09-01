#include<set>
#include<iostream>
using namespace std;

struct stu{
	int A,B;
	stu(int a,int b){
		this->A=a;
		this->B=b;
	}
	bool operator <(const stu& a) const{
		return (this->A+this->B)<(a.A+a.B);
	}
};

set<stu> sm;

int main(){
	int n,a,b;
	while(cin>>n&&n!=0){
		sm.clear();
		while(n--){
			cin>>a;
			cin>>b;
			stu ply1(a,b);   //一个学生
			stu ply2(b,a); 
			if(sm.count(ply2)!=0) sm.erase(ply2);
			else sm.insert(ply1);
		}
		if(sm.empty()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
