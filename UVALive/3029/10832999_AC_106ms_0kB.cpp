#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e3+11;
char G[maxn][maxn],str[5],GG[maxn][maxn];
int up[maxn][maxn],l[maxn][maxn],r[maxn][maxn];
int n,m;
int solve(){
	int ans=0;
	for(int i = 0; i < n; i++){
		int lo=-1,hi=m;
		for(int j = 0; j < m; j++){
			if(G[i][j]=='R'){
				up[i][j]=l[i][j]=0;lo=j;
			}
			else{
				up[i][j]=i==0?:up[i-1][j]+1;
				l[i][j]=i==0?lo+1:max(l[i-1][j],lo+1);
			}
		}
		for(int j = m-1; j >= 0; j--){
			if(G[i][j]=='R'){
				r[i][j]=m;
				hi=j; 
			}
			else{
				r[i][j]=i==0?hi-1:min(r[i-1][j],hi-1);
				ans=max(ans,up[i][j]*(r[i][j]-l[i][j]+1));
			}
		}
	}
	return ans;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		memset(G,0,sizeof G);memset(GG,0,sizeof GG);memset(up,0,sizeof up);memset(l,0,sizeof l);memset(r,0,sizeof r);
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
			scanf("%s",str);
			G[i][j]=str[0];
		} 
		printf("%d\n",solve()*3);
	}
	return 0;
} 