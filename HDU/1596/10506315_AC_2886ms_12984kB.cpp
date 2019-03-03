#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1200; 
double d[maxn][maxn];
int n,m,from,to;
void floyd(){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++) if(i!=j){
				d[i][j]=max(d[i][j],d[i][k]*d[k][j]);
			}
		}
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(d,0,sizeof d);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%lf",&d[i][j]);
			}
		}
		scanf("%d",&m);floyd();
		for(int i = 0; i < m; i++){
			scanf("%d%d",&from,&to);
			if(d[from-1][to-1]==0) printf("What a pity!\n");
			else printf("%.3lf\n",d[from-1][to-1]);
		}
	}
	return 0;
}