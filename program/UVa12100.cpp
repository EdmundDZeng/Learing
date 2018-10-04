#include<queue>
#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int pri,id;
	Node(const int& a,const int& b):pri(a),id(b){}
	bool operator <(const Node&a)const{
		return this->pri<a.pri;
	}
};
void print(const int& own, priority_queue<int,vector<int> > pq, queue<Node> aq){
	int time=0;
	for(;;){
	int fis=aq.front().pri; int max=pq.top();
	if(fis<max) {
		Node temp=aq.front();
		aq.pop();
		aq.push(temp);
	}
	else if(fis==max){
		time++;
		pq.pop();
		Node temp=aq.front();
		if(temp.id==own) break;
		else aq.pop();
	}
}
    cout<<time<<endl;
}
int main() {
	int T,n,m;   //n:任务数 m:自己的任务位置 
	cin>>T;
	while(T--){
		cin>>n>>m;
		priority_queue<int,vector<int> > pq;
        queue<Node> aq;
		for(int i=0;i<n;i++){
			int temp_num;cin>>temp_num;   //读入优先级 
			Node temp_nd(temp_num,i);
			pq.push(temp_num); aq.push(temp_nd);
		}
	    print(m,pq,aq);
	}
	return 0;
}
