#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 555+11;
const int mod = 1e9+7;
typedef long long ll;
ll dp[maxn][maxn];
int main(){
	int T,n,m; scanf("%d",&T);
	n=500;m=500;dp[0][0]=1;
	rep(i,1,m) dp[0][i]=1;
	rep(i,1,n) dp[i][0]=1;
	rep(i,1,n) rep(j,1,m){
		dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
	}
	while(T--){
		scanf("%d%d",&n,&m);
		printf("%lld\n",dp[n][m]%mod);
	}
	return 0;
}