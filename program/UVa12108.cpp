#include<stdio.h>
#define maxd 15
#include<iostream>
using namespace std;
int n,kase=0;
int t;
int m[maxd]={0};       //当前时刻学生在周期的位置 
int f[maxd]={0};      //当前学生状态 0：睡着 1：醒着  2:临睡 
int flag=0;        //清醒人数 
int C[maxd]={0};

struct student{
	int A,B,C;
}stu[maxd];

int isSame(int h){
	for(int i=0;i<h;i++){
		if(stu[i].C!=m[i]) return 0;
	}
	return 1;
}

int main(){
	while(cin>>n&&n){
		kase++;
		for(int i=0;i<n;i++){
			cin>>stu[i].A>>stu[i].B>>stu[i].C;
			C[i]=stu[i].C;
		}
		t=1;
		while(!isSame(n)){
			t++;
			flag=0;
			for(int i=0;i<n;i++){
				m[i]=(C[i]+t-1)%(stu[i].A+stu[i].B);
				// if(f[i]==2) { if(flag>=n-flag) stu[i].C=1;	}
				if(m[i]<stu[i].A&&m[i]!=0) { f[i]=1; flag++;}
				if(m[i]==stu[i].A) { f[i]=2; flag++;}
				if(m[i]==0) { m[i]=stu[i].A+stu[i].B; f[i]=1;}
				if(m[i]>stu[i].A) f[i]=0;
			}
			for(int i=0;i<n;i++){
				if(f[i]==2) { if(flag>=n-flag) C[i]=C[i]+stu[i].B;	}
			}
			int j;
			for(j=0;j<n;j++){
				if(f[j]==1||f[j]==2) continue;
				else break;
			}
			if(j==n) {
			printf("Case %d: %d\n",kase,t);
			break;
		}
		}
		if(isSame(n)) printf("Case %d: -1\n",kase);
	}
	return 0;
}
