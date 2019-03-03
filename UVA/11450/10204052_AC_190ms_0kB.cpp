#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 1e2, INF = 0x3f3f3f3f;
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
	ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--){
		memset(dp,-1,sizeof dp);
		cin>>M>>C;
		for(int i = 0; i < C; i++){
			cin>>g[i][0];
			for(int j = 1; j <= g[i][0]; j++){
				cin>>g[i][j];
			}
		}
		int ans = DP(0,M);//NOTE 0-based
		if(ans!=-1) cout<<ans<<endl;
		else cout<<"no solution"<<endl;
	}
	return 0;
} 