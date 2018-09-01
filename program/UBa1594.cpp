#include<queue>
#include<iostream>
#include<vector>
using namespace std;

int n;

int main(){
	vector<int> dis;
	int rem;
	while(cin>>n&&n!=0){
		queue<int> card;
		dis.clear();
		for(int i=1;i<=n;i++)
		card.push(i);
		for(;;){
			int tep=card.front();
			card.pop();
			if(card.empty()){
				rem=tep;
				break;
			}
			dis.push_back(tep);
			tep=card.front();
			card.pop();
			card.push(tep);
		}
		cout<<"Discarded cards:";
		for(int i=0;i<dis.size();i++){
			if(i!=dis.size()-1) cout<<" "<<dis[i]<<",";
			else cout<<" "<<dis[i]<<endl;
		}
		cout<<"Remaining card:"<<" "<<rem<<endl;
	}
	return 0;
} 
