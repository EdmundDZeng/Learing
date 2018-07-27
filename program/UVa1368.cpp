#include<stdio.h>
#define maxn 100000000

int main(){
	int T;
	int m,n;
	scanf("%d",&T);
	int Ham=0;
	int min=maxn;
	while(T--)
	{   
		while(scanf("%d %d",&m,&n)==2)
		{
			Ham=0;
			char Best[n+5]={'\n'};
			char DNA[m+5][n+5];
			int minA=0,minT=0,minC=0,minG=0;
			for(int i=0;i<m;i++)
			scanf("%s",DNA[i]);
			for(int j=0;j<n;j++)
			{
				minA=0;
				minT=0;
				minC=0;
				minG=0;
				min=maxn;
				for(int i=0;i<m;i++)
				{
					if(DNA[i][j]!='A') minA++;
					if(DNA[i][j]!='T') minT++;
					if(DNA[i][j]!='C') minC++;
					if(DNA[i][j]!='G') minG++;
			    }
				if(min>minA) min=minA;
				if(min>minC) min=minC;
				if(min>minG) min=minG;
				if(min>minT) min=minT;
				if(min==minA) {
					Best[j]='A';
					Ham+=min;
					continue;
				}
				else if(min==minC) {
					Best[j]='C';
					Ham+=min;
					continue;
				} 
				else if(min==minG) {
					Best[j]='G';
					Ham+=min;
					continue;
				} 
				else if(min==minT) {
					Best[j]='T';
					Ham+=min;
				    continue;
				}
			}
			printf("%s\n",Best);
			printf("%d\n",Ham);
		}
	}

return 0;
}
