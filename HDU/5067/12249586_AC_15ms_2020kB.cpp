#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
typedef pair<int,int> P;
int dp[1<<12][20];
int G[56][78],r,c;
P biao[23];
inline int dis(P a,P b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int DP(int S,int v,int cnt){
	if(dp[S][v]>=0) return dp[S][v];
	if(S==(1<<cnt)-1&&v==0) return dp[S][v]=0;
	int ans=0x3f3f3f3f;
	rep(u,0,cnt-1){
		if(!(S>>u&1)){
			ans=min(ans,DP(S|(1<<u),u,cnt)+dis(biao[u],biao[v]));
		}
	}
	return dp[S][v]=ans;
}
int main(){
	while(scanf("%d%d",&r,&c)!=EOF){
		int cnt=0;
		rep(i,0,r-1)rep(j,0,c-1)scanf("%d",&G[i][j]);
		rep(i,0,r-1)rep(j,0,c-1){
			if(G[i][j]||(i==0&&j==0)){
				biao[cnt++]=P(i,j);
			}
		}
		memset(dp,-1,sizeof dp);
		printf("%d\n",DP(0,0,cnt));
	}
	return 0;
}