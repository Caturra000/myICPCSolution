#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int dp[1<<18][17];
int G[18][18],n,m,u,v,w;
int DP(int S,int u,int n){
	if(dp[S][u]>=0) return dp[S][u];
	if(S==(1<<n)-1&&u==0) return dp[S][u]=0;
	int ans=0x3f3f3f3f;
	rep(v,0,n-1){
		if(!(S>>v&1)){
			ans=min(ans,DP(S|(1<<v),v,n)+G[u][v]);
		}
	}
	return dp[S][u]=ans;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(G,0x3f,sizeof G);
		memset(dp,-1,sizeof dp);
		rep(i,1,m){
			scanf("%d%d%d",&u,&v,&w);
			u--; v--;
			G[u][v]=min(G[u][v],w);
			G[v][u]=min(G[v][u],w);
		}
		rep(i,0,n-1) G[i][i]=0;
		rep(i,0,n-1) rep(j,0,n-1)if(i!=j){
			rep(k,0,n-1)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
		}
		printf("%d\n",DP(0,0,n));
	}
	return 0;
}