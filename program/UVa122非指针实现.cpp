#include<vector>
#include<queue>
#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;

int const maxn=256+5;
int const root=1;
int cnt;
int nleft[maxn];
int nright[maxn];
bool have_value[maxn];
int value[maxn];
bool failed;

string node;
void newtree(){
    nleft[root]=0;
    nright[root]=0;
    have_value[root]=false;
    cnt=root;
}
int newnode(){
    int u=++cnt;
    nleft[u]=nright[u]=0;
    have_value[u]=false;
    return u;
}
void addnode(int& v,string& s){
     int n=s.length();
     int u=root;
     for(int i=0;i<n;i++){
        if(s[i]=='L'){
            if(nleft[u]==0) nleft[u]=newnode();
            u=nleft[u];
        }
        else if(s[i]=='R'){
            if(nright[u]==0) nright[u]=newnode();
            u=nright[u];
        }
     }
     if(have_value[u]) failed=true;
     value[u]=v;
     have_value[u]=true;
}
bool readnode(){
    failed=false;
    newtree();
	while(cin>>node){
		int v;                   //½ÚµãÖµ
		stringstream ss;
		string move;
		string val;
		if(node[1]==')') return true;
		else {
			int found=node.find(',');
			val=node.substr(1,found-1);
			ss<<val;
			ss>>v;
			move=node.substr(found+1);
			addnode(v,move);
		}
	}
	return false;
}

bool bfs(vector<int>& ans){
    queue<int> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(!have_value[u]) return false;
        ans.push_back(value[u]);
        if(nleft[u]!=0) q.push(nleft[u]);
        if(nright[u]!=0) q.push(nright[u]);
    }
    return true;
}

int main(){
	while(readnode()){
		vector<int> out;
		if(bfs(out)&&!failed)
		for(int i=0;i<out.size();i++){
			if(i!=out.size()-1) printf("%d ",out[i]);
			else printf("%d\n",out[i]);
		}
		else printf("not complete\n");
	}
	return 0;
}
