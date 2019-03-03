#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 3e3+100;
bool G[maxn][maxn];
int n,m,from,to,x;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		memset(G,0,sizeof G);
		scanf("%d",&n);
		for(int i = 1; i <= n-1; i++){
			for(int j = i+1; j <= n; j++){
				scanf("%d",&x);
				G[i][j]=x;
				G[j][i]=G[i][j];
			}
		}
		int flag=0;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				for(int k = j+1; k <= n; k++){
					if(G[i][j]&&G[j][k]&&G[i][k]){
						flag=1;break;
					}
					if(!G[i][j]&&!G[j][k]&&!G[i][k]){
						flag=1;break;
					}
				}
			}
		}
		if(flag) printf("Bad Team!\n");
		else printf("Great Team!\n");
	}
	return 0; 
}