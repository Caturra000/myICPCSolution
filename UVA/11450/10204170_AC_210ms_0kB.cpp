#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 1e2;
int M,C,g[maxn][maxn],dp[maxn][maxn];
int DP(int cur,int money){
	if(money<0) return -1;
	if(cur==C) return M-money;
	if(dp[cur][money]!=-1) return dp[cur][money];
	int ans = -1;
	for(int i = 1; i <= g[cur][0]; i++){
		ans = max(ans,DP(cur+1,money-g[cur][i]));
	}
	return dp[cur][money] = ans;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		memset(dp,-1,sizeof dp);
		scanf("%d%d",&M,&C);
		for(int i = 0; i < C; i++){
			scanf("%d",&g[i][0]);
			for(int j = 1; j <= g[i][0]; j++){
				scanf("%d",&g[i][j]);
			}
		}
		int ans = DP(0,M);//NOTE 0-based
		if(ans!=-1) printf("%d\n",ans);
		else printf("no solution\n");
	}
	return 0;
} 