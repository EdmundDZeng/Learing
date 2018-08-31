#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int m,n;
int h[1000];
float V;
int kase=0;


int main(){
	while(cin>>m>>n&&(m||n)){
		float heg;
		float per;
		kase++;
		for(int i=0;i<m*n;i++){
			cin>>h[i];
		}
		sort(h,h+m*n);
		cin>>V;
		V=V/100;
		for(int i=0;i<m*n;i++){
			if(i==m*n-1){
				heg=h[i]+V/(i+1);
				per=(float)(i+1)/(m*n);
				break;
			}
			V=V-(h[i+1]-h[i])*(i+1);
			if(V<=0){
				heg=h[i+1]+V/(i+1);
				per=(float)((i+1)*100)/(m*n);
				break;
			}
		}
		printf("Region %d\n",kase);
		printf("Water level is %.2f meters.\n",heg);
		printf("%.2f percent of the region is under water.\n\n",per);
		
	}
	return 0;
}
